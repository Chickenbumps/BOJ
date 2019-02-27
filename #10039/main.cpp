#include <iostream>
using namespace std;

int main()
{
    int i_Score[5];
    int i_Total =0;
    for (int i = 0; i < 5; ++i)
    {
        cin >> i_Score[i];
        if(i_Score[i] < 40)
            i_Score[i] = 40;
        i_Total += i_Score[i];
    }
    cout << i_Total /5 << "\n";
    return 0;
}