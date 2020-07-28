//
//  main.cpp
//  #2589
//
//  Created by 조해성 on 2020/05/17.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define MAX 50
using namespace std;

int visited[MAX][MAX];
char map[MAX][MAX];
int countLength;
int y[] = {0, 0, -1, 1};
int x[] = {-1, 1, 0, 0};
int width,height;
int maxLength = 0;
void init()
{
    cin >> height >> width;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> map[i][j];
        }
    }
}

void bfs(int col, int row)
{
    memset(visited,0,sizeof(visited));
    queue<pair<int,int>> q;
    visited[col][row] = 1;
    q.push({col, row});
    while (!q.empty()) {
        col = q.front().first;
        row = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int c = col + y[i];
            int r = row + x[i];
            if (r < width && r > -1 && c < height && c > -1) {
                if (visited[c][r] == 0 && map[c][r] == 'L') {
                    visited[c][r] = visited[col][row] + 1;
                    q.push({c, r});
                    countLength = max(countLength, visited[c][r]);
                }
            }
        }
        
    }
}
int main(int argc, const char * argv[]) {
    init();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == 'L') {
                bfs(i,j);
                maxLength = max(countLength,maxLength);
                countLength = 0;
            }
        }
    }
    cout << maxLength -1;
    return 0;
}
