// 2020/OS/CPU Scheduling Simulator/B411205/조해성
// CPU Schedule Simulator Homework
// Student Number :B411205
// Name :조해성
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

#define SEED 10

// process states
#define S_IDLE 0
#define S_READY 1
#define S_BLOCKED 2
#define S_RUNNING 3
#define S_TERMINATE 4

int NPROC, NIOREQ, QUANTUM;

struct ioDoneEvent {
    int procid;
    int doneTime;
    int len;
    struct ioDoneEvent *prev;
    struct ioDoneEvent *next;
} ioDoneEventQueue, *ioDoneEvent;

struct process {
    int id;
    int len;        // for queue
    int targetServiceTime;
    int serviceTime;
    int startTime;
    int endTime;
    char state;
    int priority;
    int saveReg0, saveReg1;
    struct process *prev;
    struct process *next;
} *procTable;

struct process idleProc;
struct process readyQueue;
struct process blockedQueue;
struct process *runningProc;

int cpuReg0, cpuReg1;
int currentTime = 0;
int *procIntArrTime, *procServTime, *ioReqIntArrTime, *ioServTime;

void compute() {
    // DO NOT CHANGE THIS FUNCTION
    cpuReg0 = cpuReg0 + runningProc->id;
    cpuReg1 = cpuReg1 + runningProc->id;
    //printf("In computer proc %d cpuReg0 %d\n",runningProc->id,cpuReg0);
}

void initProcTable() {
    int i;
    for(i=0; i < NPROC; i++) {
        procTable[i].id = i;
        procTable[i].len = 0;
        procTable[i].targetServiceTime = procServTime[i];
        procTable[i].serviceTime = 0;
        procTable[i].startTime = 0;
        procTable[i].endTime = 0;
        procTable[i].state = S_IDLE;
        procTable[i].priority = 0;
        procTable[i].saveReg0 = 0;
        procTable[i].saveReg1 = 0;
        procTable[i].prev = NULL;
        procTable[i].next = NULL;
    }

}
void procExecSim(struct process *(*scheduler)()) {
    int pid, qTime =0, cpuUseTime = 0, nproc=0, termProc = 0, nioreq=0;
    char schedule = 0, nextState = S_IDLE;
    int nextForkTime, nextIOReqTime;

    nextForkTime = procIntArrTime[nproc];
    nextIOReqTime = ioReqIntArrTime[nioreq];
    idleProc.state = S_IDLE;
    idleProc.id = 0;
    idleProc.targetServiceTime = -1;
    runningProc = &idleProc;

    while(1) {
        currentTime++;
        qTime++;
        runningProc->serviceTime++;
        
        
        if (runningProc->state != S_IDLE ) {
            cpuUseTime++;
        }
    
        // MUST CALL compute() Inside While loopa
        compute();
     
        if (currentTime == nextForkTime && nproc < NPROC) { /* CASE 2 : a new process created */
            printf("nproc: %d\n",nproc);
            procTable[nproc].state = S_READY;
            procTable[nproc].startTime = currentTime;
            if(readyQueue.len == 0){
                readyQueue.next = &procTable[nproc];
            }else {
                readyQueue.prev->next = &procTable[nproc];
            }
            readyQueue.prev = &procTable[nproc];
            readyQueue.len += 1;
            
            if(runningProc->state == S_RUNNING){//
                runningProc->state = S_READY;
                procTable[runningProc->id] = *runningProc;
                procTable[runningProc->id].saveReg0 = cpuReg0;
                procTable[runningProc->id].saveReg1 = cpuReg1;
                readyQueue.prev->next = runningProc;
                readyQueue.prev = runningProc;
                readyQueue.len += 1;
            }
            runningProc = scheduler();
            qTime = 0;
            nproc++;
            nextForkTime = procIntArrTime[nproc] + currentTime;
    
        }
        

        if (qTime == QUANTUM) { /* CASE 1 : The quantum expires */
            if(runningProc->state == S_RUNNING){
                runningProc->state = S_READY;
                procTable[runningProc->id] = *runningProc;
                procTable[runningProc->id].saveReg0 = cpuReg0;
                procTable[runningProc->id].saveReg1 = cpuReg1;
                if(readyQueue.len == 0){
                    readyQueue.next = &procTable[runningProc->id];
                }
                else {
                    readyQueue.prev->next = &procTable[runningProc->id];
                }
                readyQueue.prev = &procTable[runningProc->id];
                readyQueue.len += 1;
                runningProc = scheduler();
            }
            qTime = 0;
        }
        
        while (ioDoneEventQueue.next->doneTime == currentTime) { /* CASE 3 : IO Done Event */
            pid = ioDoneEventQueue.next->procid;
            //printf("pid:%d id:%d state:%d",pid,procTable[pid].id,procTable[pid].state);
            if(procTable[pid].state != S_TERMINATE){
                if(blockedQueue.len > 0){
                    blockedQueue.len -= 1;
                    blockedQueue.next->state = S_READY;
                    struct process* BtoR = (struct process*)malloc(sizeof(struct process));
                    BtoR->id = blockedQueue.next->id;
                    BtoR->len = blockedQueue.next->len;
                    BtoR->targetServiceTime = blockedQueue.next->targetServiceTime;
                    BtoR->serviceTime = blockedQueue.next->serviceTime;
                    BtoR->startTime = blockedQueue.next->startTime;
                    BtoR->endTime = blockedQueue.next->endTime;
                    BtoR->state = blockedQueue.next->state;
                    BtoR->priority = blockedQueue.next->priority;
                    BtoR->saveReg0 = blockedQueue.next->saveReg0;
                    BtoR->saveReg1 = blockedQueue.next->saveReg1;
                    BtoR->prev = NULL;
                    BtoR->next = NULL;
                    
                    if(readyQueue.len == 0){
                        readyQueue.next = BtoR;
                    }else {
                        readyQueue.prev->next = BtoR;
                    }
                    readyQueue.prev = BtoR;
                    readyQueue.len += 1;
                }
                if(blockedQueue.len == 0) {
                    blockedQueue.next = blockedQueue.prev = &blockedQueue;
                }
                if(blockedQueue.next != &blockedQueue){
                    struct process* removeP = blockedQueue.next;
                    blockedQueue.next = removeP->next;
                    //removeP->next = NULL;
                }
                
            }

            if(runningProc->state == S_RUNNING){
                runningProc->state = S_READY;
                procTable[runningProc->id] = *runningProc;
                procTable[runningProc->id].saveReg0 = cpuReg0;
                procTable[runningProc->id].saveReg1 = cpuReg1;
                if(readyQueue.len == 0){
                    readyQueue.next = &procTable[runningProc->id];
                }else {
                    readyQueue.prev->next = &procTable[runningProc->id];
                }
                readyQueue.prev = &procTable[runningProc->id];
                readyQueue.len += 1;
                runningProc = scheduler();
                qTime = 0;
            }
            ioDoneEventQueue.len -= 1;
            
            if(ioDoneEventQueue.len == 0){
                ioDoneEventQueue.next = ioDoneEventQueue.prev = &ioDoneEventQueue;
                break;
            }
            if(ioDoneEventQueue.next != &ioDoneEventQueue){
                struct ioDoneEvent* removeIo = ioDoneEventQueue.next;
                ioDoneEventQueue.next = removeIo->next;
                //removeIo->next = NULL;
            }
        }
        if (nioreq < NIOREQ && cpuUseTime == nextIOReqTime) { /* CASE 5: reqest IO operations (only when the process does not terminate) */
            ioDoneEvent[nioreq].doneTime = ioServTime[nioreq] +currentTime;
            ioDoneEvent[nioreq].procid = runningProc->id;
            if(ioDoneEventQueue.len == 0) {
                ioDoneEventQueue.next = &ioDoneEvent[nioreq];
            }else {
                ioDoneEventQueue.prev->next = &ioDoneEvent[nioreq];
            }
            ioDoneEventQueue.prev = &ioDoneEvent[nioreq];
            ioDoneEventQueue.len += 1;
            nioreq++;
            printf("nioreq:%d\n",nioreq);
            nextIOReqTime = ioReqIntArrTime[nioreq] + currentTime;//
        
            runningProc->state = S_BLOCKED;
            procTable[runningProc->id] = *runningProc;
            procTable[runningProc->id].saveReg0 = cpuReg0;
            procTable[runningProc->id].saveReg1 = cpuReg1;
            if(blockedQueue.len == 0){
                blockedQueue.next = &procTable[runningProc->id];
            } else{
                blockedQueue.prev->next = &procTable[runningProc->id];
            }
            blockedQueue.prev = &procTable[runningProc->id];
            blockedQueue.len += 1;
            
            runningProc = scheduler();
            qTime = 0;
            
        }
        
        if (runningProc->serviceTime == runningProc->targetServiceTime) { /* CASE 4 : the process job done and terminates */
            runningProc->state = S_TERMINATE;
            runningProc->endTime = currentTime;    //
            procTable[runningProc->id] = *runningProc;
            termProc++;
            printf("termProc:%d\n",termProc);
            runningProc = scheduler();
            qTime = 0;
        }
              
        
        if(termProc == NPROC) {
            printf("\n currentTime : %d\n",currentTime);
            break;
        }
        // call scheduler() if needed
    } // while loop
}

//RR,SJF(Modified),SRTN,Guaranteed Scheduling(modified),Simple Feed Back Scheduling
struct process* RRschedule() {
    if(readyQueue.len == 0){
        readyQueue.next = readyQueue.prev = &readyQueue;
        return &idleProc;
    }
    if(readyQueue.len > 0){
        readyQueue.len -= 1;
    }
    struct process *newP = (struct process*)malloc(sizeof(struct process));
    newP->id = readyQueue.next->id;
    newP->len = readyQueue.next->len;        // for queue
    newP->targetServiceTime = readyQueue.next->targetServiceTime;
    newP->serviceTime = readyQueue.next->serviceTime;
    newP->startTime = readyQueue.next->startTime;
    newP->endTime = readyQueue.next->endTime;
    newP->state = readyQueue.next->state;
    newP->priority = readyQueue.next->priority;
    newP->saveReg0 = readyQueue.next->saveReg0;
    newP->saveReg1 = readyQueue.next->saveReg1;
    newP->prev = NULL;
    newP->next = NULL;
    if(readyQueue.len == 0) readyQueue.next = readyQueue.prev = &readyQueue;
    if(readyQueue.next != &readyQueue){
        struct process* removeP = readyQueue.next;
        readyQueue.next = removeP->next;
        //removeP->next = NULL;
    }
    newP->state = S_RUNNING;
    return newP;
}
struct process* SJFschedule() {
    return runningProc;
}
struct process* SRTNschedule() {
    return runningProc;
}
struct process* GSschedule() {
    return runningProc;
}
struct process* SFSschedule() {
    return runningProc;
}

void printResult() {
        // DO NOT CHANGE THIS FUNCTION
        int i;
        long totalProcIntArrTime=0,totalProcServTime=0,totalIOReqIntArrTime=0,totalIOServTime=0;
        long totalWallTime=0, totalRegValue=0;
        for(i=0; i < NPROC; i++) {
                totalWallTime += procTable[i].endTime - procTable[i].startTime;
                /*
                printf("proc %d serviceTime %d targetServiceTime %d saveReg0 %d\n",
                        i,procTable[i].serviceTime,procTable[i].targetServiceTime, procTable[i].saveReg0);
                */
                totalRegValue += procTable[i].saveReg0+procTable[i].saveReg1;
                /* printf("reg0 %d reg1 %d totalRegValue %d\n",procTable[i].saveReg0,procTable[i].saveReg1,totalRegValue);*/
        }
        for(i = 0; i < NPROC; i++ ) {
                totalProcIntArrTime += procIntArrTime[i];
                totalProcServTime += procServTime[i];
        }
        for(i = 0; i < NIOREQ; i++ ) {
                totalIOReqIntArrTime += ioReqIntArrTime[i];
                totalIOServTime += ioServTime[i];
        }

        printf("Avg Proc Inter Arrival Time : %g \tAverage Proc Service Time : %g\n", (float) totalProcIntArrTime/NPROC, (float) totalProcServTime/NPROC);
        printf("Avg IOReq Inter Arrival Time : %g \tAverage IOReq Service Time : %g\n", (float) totalIOReqIntArrTime/NIOREQ, (float) totalIOServTime/NIOREQ);
        printf("%d Process processed with %d IO requests\n", NPROC,NIOREQ);
        printf("Average Wall Clock Service Time : %g \tAverage Two Register Sum Value %g\n", (float) totalWallTime/NPROC, (float) totalRegValue/NPROC);

}

int main(int argc, char *argv[]) {
    // DO NOT CHANGE THIS FUNCTION
    int i;
    int totalProcServTime = 0, ioReqAvgIntArrTime;
    int SCHEDULING_METHOD, MIN_INT_ARRTIME, MAX_INT_ARRTIME, MIN_SERVTIME, MAX_SERVTIME, MIN_IO_SERVTIME, MAX_IO_SERVTIME, MIN_IOREQ_INT_ARRTIME;

    if (argc < 12) {
        printf("%s: SCHEDULING_METHOD NPROC NIOREQ QUANTUM MIN_INT_ARRTIME MAX_INT_ARRTIME MIN_SERVTIME MAX_SERVTIME MIN_IO_SERVTIME MAX_IO_SERVTIME MIN_IOREQ_INT_ARRTIME\n",argv[0]);
        exit(1);
    }

    SCHEDULING_METHOD = atoi(argv[1]);
    NPROC = atoi(argv[2]);
    NIOREQ = atoi(argv[3]);
    QUANTUM = atoi(argv[4]);
    MIN_INT_ARRTIME = atoi(argv[5]);
    MAX_INT_ARRTIME = atoi(argv[6]);
    MIN_SERVTIME = atoi(argv[7]);
    MAX_SERVTIME = atoi(argv[8]);
    MIN_IO_SERVTIME = atoi(argv[9]);
    MAX_IO_SERVTIME = atoi(argv[10]);
    MIN_IOREQ_INT_ARRTIME = atoi(argv[11]);

    printf("SIMULATION PARAMETERS : SCHEDULING_METHOD %d NPROC %d NIOREQ %d QUANTUM %d \n", SCHEDULING_METHOD, NPROC, NIOREQ, QUANTUM);
    printf("MIN_INT_ARRTIME %d MAX_INT_ARRTIME %d MIN_SERVTIME %d MAX_SERVTIME %d\n", MIN_INT_ARRTIME, MAX_INT_ARRTIME, MIN_SERVTIME, MAX_SERVTIME);
    printf("MIN_IO_SERVTIME %d MAX_IO_SERVTIME %d MIN_IOREQ_INT_ARRTIME %d\n", MIN_IO_SERVTIME, MAX_IO_SERVTIME, MIN_IOREQ_INT_ARRTIME);

    srandom(SEED);

    // allocate array structures
    procTable = (struct process *) malloc(sizeof(struct process) * NPROC);
    ioDoneEvent = (struct ioDoneEvent *) malloc(sizeof(struct ioDoneEvent) * NIOREQ);
    procIntArrTime = (int *) malloc(sizeof(int) * NPROC);
    procServTime = (int *) malloc(sizeof(int) * NPROC);
    ioReqIntArrTime = (int *) malloc(sizeof(int) * NIOREQ);
    ioServTime = (int *) malloc(sizeof(int) * NIOREQ);

    // initialize queues
    readyQueue.next = readyQueue.prev = &readyQueue;

    blockedQueue.next = blockedQueue.prev = &blockedQueue;
    ioDoneEventQueue.next = ioDoneEventQueue.prev = &ioDoneEventQueue;
    ioDoneEventQueue.doneTime = INT_MAX;
    ioDoneEventQueue.procid = -1;
    ioDoneEventQueue.len  = readyQueue.len = blockedQueue.len = 0;

    // generate process interarrival times
    for(i = 0; i < NPROC; i++ ) {
        procIntArrTime[i] = random()%(MAX_INT_ARRTIME - MIN_INT_ARRTIME+1) + MIN_INT_ARRTIME;
    }

    // assign service time for each process
    for(i=0; i < NPROC; i++) {
        procServTime[i] = random()% (MAX_SERVTIME - MIN_SERVTIME + 1) + MIN_SERVTIME;
        totalProcServTime += procServTime[i];
    }

    ioReqAvgIntArrTime = totalProcServTime/(NIOREQ+1);

    // generate io request interarrival time
    for(i = 0; i < NIOREQ; i++ ) {
        ioReqIntArrTime[i] = random()%((ioReqAvgIntArrTime - MIN_IOREQ_INT_ARRTIME)*2+1) + MIN_IOREQ_INT_ARRTIME;
    }

    // generate io request service time
    for(i = 0; i < NIOREQ; i++ ) {
        ioServTime[i] = random()%(MAX_IO_SERVTIME - MIN_IO_SERVTIME+1) + MIN_IO_SERVTIME;
    }
//#ifdef DEBUG
//    // printing process interarrival time and service time
//    printf("Process Interarrival Time :\n");
//    for(i = 0; i < NPROC; i++ ) {
//        printf("%d ",procIntArrTime[i]);
//    }
//    printf("\n");
//    printf("Process Target Service Time :\n");
//    for(i = 0; i < NPROC; i++ ) {
//        printf("%d ",procTable[i].targetServiceTime);
//    }
//    printf("\n");
//
//    // printing io request interarrival time and io request service time
//    printf("IO Req Average InterArrival Time %d\n", ioReqAvgIntArrTime);
//    printf("IO Req InterArrival Time range : %d ~ %d\n",MIN_IOREQ_INT_ARRTIME,
//            (ioReqAvgIntArrTime - MIN_IOREQ_INT_ARRTIME)*2+ MIN_IOREQ_INT_ARRTIME);
//#endif
//#ifdef DEBUG
//    printf("IO Req Interarrival Time :\n");
//    for(i = 0; i < NIOREQ; i++ ) {
//        printf("%d ",ioReqIntArrTime[i]);
//    }
//    printf("\n");
//    printf("IO Req Service Time :\n");
//    for(i = 0; i < NIOREQ; i++ ) {
//        printf("%d ",ioServTime[i]);
//    }
//    printf("\n");
//#endif
//
    struct process* (*schFunc)();
    switch(SCHEDULING_METHOD) {
        case 1 : schFunc = RRschedule; break;
        case 2 : schFunc = SJFschedule; break;
        case 3 : schFunc = SRTNschedule; break;
        case 4 : schFunc = GSschedule; break;
        case 5 : schFunc = SFSschedule; break;
        default : printf("ERROR : Unknown Scheduling Method\n"); exit(1);
    }
    initProcTable();
    procExecSim(schFunc);
    printResult();

}
