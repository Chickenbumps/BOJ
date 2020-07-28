//
//  main.cpp
//  #2178
//
//  Created by 조해성 on 2020/05/22.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
#define MAX 102

char map[MAX][MAX];
int visited[MAX][MAX];
int N,M;
int y[] = {1, -1, 0, 0};
int x[] = {0, 0, 1, -1};
int countNum = 0;
queue<pair<int, int> > q;

void init(){
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> map[i][j];
        }
    }
}

void bfs(int row, int col){
    visited[row][col] = 1;
    q.push(make_pair(row,col));
    while (!q.empty()) {
        row = q.front().first;
        col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int c = col + x[i];
            int r = row + y[i];
            if (c <= M && c > 0 && r <= N && r > 0 && visited[r][c] == 0 && map[r][c] == '1')
            {
                visited[r][c] = visited[row][col] + 1;
                q.push(make_pair(r, c));
            }
        }
    }
    cout << visited[N][M];
}
int main(int argc, const char * argv[]) {
    init();
    bfs(1,1);
    return 0;
}
