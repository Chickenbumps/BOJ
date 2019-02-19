//
//  main.cpp
//  #9498
//
//  Created by 조해성 on 16/02/2019.
//  Copyright © 2019 조해성. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int i_Score;
    cin >> i_Score;
    switch (i_Score/10) {
        case 9:
        case 10:
            cout << 'A';
            break;
        case 8:
            cout << 'B';
            break;
        case 7:
            cout << 'C';
            break;
        case 6:
            cout << 'D';
            break;
        default:
            cout << 'F';
            break;
    }
    return 0;
}
