//
//  main.cpp
//  #1110
//
//  Created by 조해성 on 16/02/2019.
//  Copyright © 2019 조해성. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int i_Input;
    cin >> i_Input;
    int i_Copy = i_Input;
    int i =0;
    do{
        if(i_Input < 10)
        {
            i_Input *=11;
        }
        else
        {
            int temp;
            temp = i_Input /10 + i_Input%10;
            i_Input = (i_Input%10)*10 + temp%10;
        }
        i++;
    }
    while(i_Copy != i_Input);
    cout << i;
    return 0;
}
