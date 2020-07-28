//
//  main.cpp
//  #1260
//
//  Created by 조해성 on 2020/05/21.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1002

int edge[MAX][MAX];
bool visited[MAX];
int edgeNum;
int vertexNum;
int startNum;
vector<int> vBfs;
vector<int> vDfs;
queue<int>  q;

void init(){
    cin >> vertexNum >> edgeNum >> startNum;
    int to,from;
    memset(edge, 0, sizeof(edge));
    for (int i = 1 ; i <= edgeNum; ++i) {
        cin >> to >> from;
        edge[to][from] = 1;
        edge[from][to] = 1;
    }
}
void dfs(int start){
    visited[start] = true;
    vDfs.push_back(start);
    for (int i = 1 ; i <= vertexNum; ++i) {
        if (!visited[i] && edge[start][i] == 1 && edge[i][start] == 1) {
            dfs(i);
        }
    }
}
void bfs(int start){
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        start = q.front();
        vBfs.push_back(q.front());
        q.pop();
        for (int i = 1; i <= vertexNum ; ++i) {
            if(!visited[i] && edge[start][i] == 1 && edge[i][start] == 1 ){
                
                visited[i] = true;
                q.push(i);
            }
        }
        
    }
}


int main(int argc, const char * argv[]) {
    init();
    dfs(startNum);
    memset(visited, 0, sizeof(visited));
    bfs(startNum);
    for (int i = 0; i < vDfs.size(); ++i) {
        cout << vDfs[i];
    }
    cout<< "\n";
    for (int i = 0; i < vBfs.size(); ++i) {
        cout << vBfs[i];
    }
    
    return 0;
}

