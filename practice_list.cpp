//
//  practice_list.cpp
//  
//
//  Created by 조해성 on 2020/05/12.
//

#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

bool visited[MAX][MAX];
bool link[MAX][MAX];
int computerNum;
int linkNum;
int virusCount = 0;
queue<int> q;

void init(){
    cin >> computerNum >> linkNum;
    int linkTo,linkFrom;
    for (int i = 1; i <= computerNum; i++) {
        cin >> linkTo >> linkFrom;
        link[linkTo][linkFrom] = true;
        link[linkFrom][linkTo] = true;
    }
}

void bfs(int start){
    q.push(start);
    visited[start] = true;
    while(!q.empty())
    {
        int start = q.front();
        q.pop(start);
        for (int i = 1; i <= computerNum; i++) {
            if(!visited[i] && link[start][i] && link[i][start])
            {
                q.push(i);
                visited[i] = true;
                virusCount++;
            }
        }
    }
}

int main(void){
    init();
    bfs(1);
    cout << virusCount;
    return 0;
}
