//
//  main.cpp
//  #7576
//
//  Created by 조해성 on 2020/05/19.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAX 1001
using namespace std;

int map[MAX][MAX];
int width,height;
int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};
int dayCount = 0;
queue<pair<int, int>> q;

void init(){
    cin >> width >> height;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1)
                q.push(make_pair(i, j));
        }
    }
}

int bfs(){
    while (!q.empty()) {
        int col = q.front().first;
        int row = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int c = col + y[i];
            int r = row + x[i];
            if(c < height && c > -1 && r < width && r > -1){
                if(map[c][r] == 0){
                    map[c][r] = map[col][row] + 1;
                    q.push(make_pair(c, r));
                }
            }
        }
    }
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if(map[i][j] == 0)
                return -1;
        }
    }
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; ++j) {
            dayCount = max(dayCount,map[i][j]);
        }
    }
    return dayCount - 1;
}
int main(int argc, const char * argv[]) {
    init();
    cout << bfs();
    return 0;
}
