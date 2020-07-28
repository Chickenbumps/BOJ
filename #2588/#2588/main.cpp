//
//  main.cpp
//  #2588
//
//  Created by 조해성 on 2020/05/30.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> v;
void init(){
    cin >> n >> m;
}

vector<int> mul(){
    vector<int> result;
    int third = m % 10;
    int second = (m % 100-third) / 10;
    int first = m / 100;
    
    int thirdResult = n * third;
    int secondResult = n * second;
    int firstResult = n * first;
    int lastResult = firstResult*100 + secondResult * 10 + thirdResult;
    result.push_back(thirdResult);
    result.push_back(secondResult);
    result.push_back(firstResult);
    result.push_back(lastResult);
    return result;
}


int main(int argc, const char * argv[]) {
    init();
    v = mul();
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
    return 0;
}
