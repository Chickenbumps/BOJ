#include <iostream>
#include <math.h>
using namespace std;

int i_DP[1000001] = {99999999};
int main()
{
    int i_N;
    cin >> i_N;
    i_DP[0] = i_DP[1] = 0;
    for (int i = 2; i <= i_N; ++i) {
        i_DP[i] = i_DP[i - 1] + 1;
        if(i % 2 ==0)
            i_DP[i] = min(i_DP[i],i_DP[i/2] + 1);
        if(i % 3 ==0)
            i_DP[i] = min(i_DP[i],i_DP[i/3] + 1);
    }
    cout << i_DP[i_N] << endl;

    return 0;
}
