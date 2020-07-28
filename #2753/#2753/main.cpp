//
//  main.cpp
//  #2753
//
//  Created by 조해성 on 2020/05/30.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int year;
    cin >> year;
    int result = 0;
    if ((year % 4 == 0 && year % 100 !=0) || year % 400 == 0) {
        result = 1;
    }
    cout << result;
    return 0;
}
