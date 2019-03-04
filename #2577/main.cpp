#include <iostream>
using namespace std;

int main() {
    int i_A,i_B,i_C;
    cin >> i_A >> i_B >> i_C;
    int i_Sum = i_A * i_B * i_C;
    int i_Num[10] ={0,};

    while(i_Sum > 0)
    {
        i_Num[i_Sum%10]++;
        i_Sum /=10;
    }
    for (int i = 0; i < 10; ++i)
    {
        cout << i_Num[i] << '\n';
    }
    return 0;
}