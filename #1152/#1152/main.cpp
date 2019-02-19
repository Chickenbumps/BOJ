//
//  main.cpp
//  #1152
//
//  Created by 조해성 on 16/02/2019.
//  Copyright © 2019 조해성. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string s_Str;
    int count =0;
    getline(cin,s_Str);
    if(s_Str.length() != 1)
        count = 1;
    for (int i = 0; i < s_Str.length(); ++i) {
        if(s_Str[i] == ' ' && i == s_Str.length() - 1 )
            break;
        if(s_Str[i] == ' ' && i != 0)
            count++;
        else if(s_Str[i] == '\0')
            break;
    }

    cout << count << endl;
    return 0;
}
