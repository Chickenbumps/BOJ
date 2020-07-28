//
//  main.cpp
//  #2468
//
//  Created by 조해성 on 2020/05/29.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <vector>
#include <functional>

using namespace std;

#define MAX 101

void bfs(int,int);
void rain();
int n;
int map[MAX][MAX];
int visited[MAX][MAX];
int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};
int maxHeight = 0;
int component = 0;
int maxComponent = 0;
queue<pair<int, int> > q;
vector<int> v;

void init(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            maxHeight = max(map[i][j], maxHeight);
        }
    }
    for (int m = maxHeight; m >= 0; m--) {
        rain();
        for (int k = 0; k < n; k++){
            for (int l = 0 ; l < n; l++) {
                bfs(k,l);
            }
        }
        maxHeight--;
        v.push_back(component);
        component = 0;
        memset(visited, 0, sizeof(visited));
    }
}


void rain(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(map[i][j] <= maxHeight)
            {
                visited[i][j] = 1;
            }
            
        }
    }
}

void bfs(int col, int row){
    if(visited[col][row] == 0){
        visited[col][row] = 1;
        q.push(make_pair(col, row));
        while (!q.empty()) {
            col = q.front().first;
            row = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int c = col + y[i];
                int r = row + x[i];
                if (visited[c][r] == 0 && c > -1 && c < n && r > -1 && r < n) {
                    visited[c][r] = 1;
                    q.push(make_pair(c, r));
                }
            }
        }
        component++;
    }
}
int main(int argc, const char * argv[]) {
    init();
    //sort(v.begin(),v.end(),greater<int>());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
        
    }
    return 0;
}
