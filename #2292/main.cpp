#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    int i_Count = 0;
    int i = 1;
    while(true)
    {
        ll a_n = 3*i*(i-1) + 1;

        if(N <= a_n)
        {
            i_Count++;
            break;
        }
        i_Count++;
        i++;
    }

    cout << i_Count;
    return 0;
}