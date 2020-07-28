//
//  main.cpp
//  #1697
//
//  Created by 조해성 on 2020/05/23.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
#include <queue>
#define MAX  100001
using namespace std;

int link[MAX][MAX];
int map[MAX];
int timeNum = 0;
int n,k;
queue<int> q;
int x[] = {1,-1};

void init(){
    cin >> n >> k;
    for (int i = 1; i <= MAX; i++) {
        link[i][i+1] = 1;
        link[i+1][i] = 1;
        link[i][2*i] = 1;
        link[2*i][i] = 1;
    }
}

void bfs(int start, int end){
    map[start] = 0;
    while (!q.empty()) {
        start = q.front();
        q.pop();
        int s;
        for (int i = 0; i < 2 ; i++) {
            if (start > 0 && end < MAX) {
                statements
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    return 0;
}
