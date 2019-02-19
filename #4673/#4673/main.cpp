//
//  main.cpp
//  #4673
//
//  Created by 조해성 on 17/02/2019.
//  Copyright © 2019 조해성. All rights reserved.
//

#include <iostream>
using namespace std;
// Self Number
int SelfNumber[100000]= {0,};

int FuncDigit(int x){
    int digit = 1;
    while(x / 10 != 0)
    {
        digit++;
        x /= 10;
    }
    
    return  digit;
}

int main(int argc, const char * argv[]) {
    int i_X;
    int i_Digit;
    for (int i = 1; i < 10001; ++i)
    {
        i_Digit = FuncDigit(i);
        int Decimal = 1;
        int temp = i;
        for(int k =1; k < i_Digit; k++)
            Decimal*=10;
        i_X = i;
        for (int j = 0; j < i_Digit; ++j)
        {
            
            i_X += (temp/Decimal);
            temp -= ((temp/Decimal) * Decimal);
            Decimal /=10;
        }
        SelfNumber[i_X] = i_X;
    }
    
    for(int i = 1; i < 10001; ++i)
    {
        if (SelfNumber[i] == 0) {
            cout << i << endl;
        }
    }
    return 0;
}
