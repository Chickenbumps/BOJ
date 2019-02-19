//
//  main.cpp
//  #10871
//
//  Created by 조해성 on 16/02/2019.
//  Copyright © 2019 조해성. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int i_N,i_X;
    std::cin >> i_N >> i_X;
    int i_A[i_N];
    for(int i = 0; i < i_N; i++)
    {
        std::cin >> i_A[i];
    }
    
    for (int j = 0; j < i_N; j++) {
        if(i_A[j] < i_X)
        {
            std::cout << i_A[j] << " ";
        }
    }
    
    return 0;
}
