//
//  main.cpp
//  #2606
//
//  Created by 조해성 on 2020/05/13.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
#include <stack>
#define MAX 101
using namespace std;

stack<int> s;
int virusCount = 0;
int linkNum;
int computerNum;
bool visited[MAX];
bool link[MAX][MAX];

void init(){
    cin >> computerNum >> linkNum;
    int linkTo,linkFrom;
    for (int i = 1; i <= linkNum; i++) {
        cin >> linkTo >> linkFrom;
        link[linkTo][linkFrom] = true;
        link[linkFrom][linkTo] = true;
    }
}

void dfs(int start){
    visited[start] = true;
    s.push(start);
    while (!s.empty()) {
        int flag = false;
        start = s.top();
        for (int j = 1; j <= computerNum; j++) {
            if (!visited[j] && link[j][start] && link[start][j]) {
                visited[j] = true;
                virusCount++;
                s.push(j);
                flag = true;
                break;
            }
        }
       if(!flag) s.pop();
        
    }
}

void dfsRecursion(int start){
    visited[start] = true;
    for (int i = 1; i <= computerNum; i++) {
        if(!visited[i] && link[i][start] && link[start][i]){
            virusCount++;
            dfsRecursion(i);
        }
    }
}


int main(int argc, const char * argv[]) {
    init();
    dfs(1);
    dfsRecursion(1);
    cout << virusCount;
    return 0;
}
