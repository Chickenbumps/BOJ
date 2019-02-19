//
//  main.cpp
//  #2750
//
//  Created by 조해성 on 16/02/2019.
//  Copyright © 2019 조해성. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;

int compare(const void* a, const void* b)
{
    const int* x = (int*)a;
    const int* y = (int*)b;
    
    if(*x > *y)
        return 1;
    else if(*x < *y)
        return -1;
    return 0;
}

int main(int argc, const char * argv[]) {
    int i_Input;
    cin >> i_Input;
    int arr[i_Input];
    for(int i =0; i < i_Input; i++)
    {
        cin >> arr[i];
    }
    qsort(arr, i_Input, sizeof(int), compare);
    
    for(int i = 0; i < i_Input; i++)
    {
        cout<< arr[i] << endl;
    }
    return 0;
}
