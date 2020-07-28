//
//  main.cpp
//  #6603
//
//  Created by 조해성 on 2020/05/27.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int k;
int input[50];
int num[50];

void init(){
    for (int i = 0; i < k; ++i) {
        cin >> input[i];
    }
}

void dfs(int s, int countNum){
    if (countNum == 6) {
        for (int i = 0; i < 6; ++i) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = s; i < k; ++i) {
        num[countNum] = input[i];
        dfs(i+1, countNum+1);
    }
}

int main(int argc, const char * argv[]) {
    while (cin >> k && k) {
        init();
        dfs(0,0);
        cout << '\n';
    }
    return 0;
}
