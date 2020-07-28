//
//  main.cpp
//  #14683
//
//  Created by 조해성 on 2020/05/30.
//  Copyright © 2020 조해성. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;
int start[2],dest[2];
int energy;
void init(){
    cin >> start[0] >> start[1] >> dest[0] >> dest[1] >> energy;
    
}
void solve(){
    int xDiff = abs(dest[0] - start[0]);
    int yDiff = abs(dest[1] - start[1]);
    
    if((energy >= xDiff + yDiff) && (energy-xDiff-yDiff) % 2 == 0)
        cout << "Y";
    else
        cout << "N";
    
}

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}
