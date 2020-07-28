//
//  main.cpp
//  #11403
//
//  Created by 조해성 on 2020/05/25.
//  Copyright © 2020 조해성. All rights reserved.
//
// 해결 X
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 101
char map[MAX][MAX];
int visited[MAX];
int path[MAX][MAX];
queue<int> q;
int vertex;
void bfs(int);

void init(){
    cin >> vertex;
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            if(i == j)
                path[i][j] = 1;
            if(map[i][j] == '1'){
                memset(visited, 0, sizeof(visited));
                bfs(i);
            }
        }
    }
}

void bfs(int start){
    visited[start] = 1;
    q.push(start);
    while (!q.empty()) {
        start = q.front();
        q.pop();
        for (int i = 0; i < vertex; i++) {
            if (map[start][i] == '1' && !visited[i]) {
                q.push(i);
               
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    init();
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << path[i][j];
        }
        cout << "\n";
    }
    return 0;
}
