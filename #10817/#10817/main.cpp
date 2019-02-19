//
//  main.cpp
//  #10817
//
//  Created by 조해성 on 16/02/2019.
//  Copyright © 2019 조해성. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int i_A,i_B,i_C;
    cin >> i_A >> i_B >> i_C;
    int i_Middle = i_A;
    
    if(i_Middle > i_B)
    {
        if(i_Middle > i_C)
        {
            if(i_B >i_C)
                i_Middle = i_B;
            else
                i_Middle = i_C;
        }
    }
    else if(i_Middle < i_B)
    {
        if(i_Middle < i_C)
        {
            if(i_B < i_C)
                i_Middle = i_B;
            else
                i_Middle =i_C;
        }
    }
    cout << i_Middle;
    return 0;
}
