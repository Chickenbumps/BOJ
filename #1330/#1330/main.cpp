//
//  main.cpp
//  #1330
//
//  Created by 조해성 on 2020/05/30.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
string diff(){
    int n,m;
    cin >> n >> m;
    if (n > m) {
        return ">";
    }
    else if(n < m){
        return "<";
    }
    else{
        return "==";
    }
}
int main(int argc, const char * argv[]) {
    string s = diff();
    cout << s;
    
    
    return 0;
}
