//
//  main.cpp
//  #14682
//
//  Created by 조해성 on 2020/05/30.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int num, plusCount;
    cin >> num >> plusCount;
    int tmp = 0,mulTemp = num;
    while (plusCount--) {
        tmp += 10*mulTemp;
        mulTemp *=10;
    }
    cout << num + tmp;
    return 0;
}
