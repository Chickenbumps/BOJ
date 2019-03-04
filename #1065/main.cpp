#include <iostream>
using namespace std;
int main() {
    int i_N;
    cin >> i_N;
    int i_Count = 0;
    for(int i = 1 ; i <= i_N; i++)
    {
        int i_a = i / 100;
        int i_b = (i%100) /10;
        int i_c = ((i%100) %10);

        if(i < 100)
            i_Count++;
        else if((2*i_b) == i_a + i_c)
        {
            i_Count++;
        }
    }

    cout << i_Count;
    return 0;
}