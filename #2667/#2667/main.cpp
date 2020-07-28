//
//  main.cpp
//  #2667
//
//  Created by 조해성 on 2020/05/14.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 25

char map[MAX][MAX];
int mapSize;
vector<int> aptNum;
int x[] = {0,0,-1,1};
int y[] = {-1,1,0,0};

void init(){
    cin >> mapSize;
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            cin >> map[i][j];
        }
    }
}

int dfs(int row, int col) {
    aptNum.reserve(25*25);
    map[row][col] = '0';
    int house = 1;
    int r,c;
    for (int i = 0; i < 4; i++) {
        r = row + x[i];
        c = col + y[i];
        if (r >=0 && c >= 0 && map[r][c] == '1' && r < mapSize && c < mapSize) {
            house += dfs(r,c);
        }
    }
    return house;
}

int main(int argc, const char * argv[]) {
    init();
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            if (map[i][j] == '1') {
                aptNum.push_back(dfs(i,j));
            }
        }
    }
    sort(aptNum.begin(), aptNum.end());
    cout << aptNum.size() << endl;
    for (int i = 0 ; i < aptNum.size(); i++) {
        cout << aptNum[i] << endl;
    }
    return 0;
}
