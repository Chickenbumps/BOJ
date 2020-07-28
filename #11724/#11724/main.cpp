//
//  main.cpp
//  #11724
//
//  Created by 조해성 on 2020/05/25.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001
int N,M;
int link[MAX][MAX];
int visited[MAX];
int componentCount = 0;
queue<int> q;
int visitCount = 0;
void bfs(int);

void init(){
    cin >> N >> M;
    int a,b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        link[a][b] = 1;
        link[b][a] = 1;
    }
    for (int j = 1; j <= N; j++) {
        for (int k = 1; k <= N; k++) {
            if (link[j][k] == 1 && visited[j] == 0) {
                bfs(j);
            }
        }
    }
}

void bfs(int start){
    visited[start] = 1;
    visitCount++;
    q.push(start);
    while (!q.empty()) {
        start = q.front();
        q.pop();
        for (int i = 1; i <= N; i++) {
            if (link[i][start] == 1 && !visited[i]) {
                visited[i] = 1;
                visitCount++;
                q.push(i);
            }
        }
    }
    componentCount++;
}
int main(int argc, const char * argv[]) {
    init();
    cout << componentCount + N-visitCount;
    return 0;
}
