//
//  main.cpp
//  #1012
//
//  Created by 조해성 on 2020/05/23.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
#include <queue>
#include <utility>
#define MAX 51
using namespace std;
void bfs(int,int);

int map[MAX][MAX];
int visited[MAX][MAX];
queue<pair<int,int> > q;
int width,height;
int cabbagesNum;
int testCase;
int wormNum = 0;
int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};

void init(){
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    wormNum = 0;
    cin >> width >> height >> cabbagesNum;
    int a,b;
    for (int i = 0; i < cabbagesNum; i++) {
        cin >> a >> b;
        map[b][a] = 1;
    }
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if(map[i][j] == 1 && visited[i][j] == 0){
                bfs(i,j);
            }
        }
    }
}

void bfs(int col, int row){
    visited[col][row] = 1;
    q.push(make_pair(col,row));
    while (!q.empty()) {
        col = q.front().first;
        row = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int c = col + x[i];
            int r = row + y[i];
            if (visited[c][r] == 0 && c > -1 && c < height && r > -1 && r < width && map[c][r] == 1) {
                visited[c][r] = 1;
                q.push(make_pair(c, r));
            }
        }
    }
    wormNum++;
}

int main(int argc, const char * argv[]) {
    cin >> testCase;
    for (int i = 0; i < testCase; ++i) {
        init();
        cout << wormNum << "\n";
    }
    return 0;
}
