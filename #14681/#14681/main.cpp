//
//  main.cpp
//  #14681
//
//  Created by 조해성 on 2020/05/30.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int x,y;
    int n;
    cin >> x >> y;
    if (x > 0 && y > 0) {
        n = 1;
    }
    else if(x < 0 && y > 0){
        n = 2;
    }else if(x <0 && y < 0){
        n = 3;
    }else
        n = 4;
    cout << n;
    return 0;
}
