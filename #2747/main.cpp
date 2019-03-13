#include <iostream>
using namespace std;

int main() {
    int i_Input;
    cin >> i_Input;
    int i_Result;
    if(i_Input == 0)
        i_Result = 0;
    else if(i_Input == 1)
        i_Result = 1;
    else if(i_Input > 1)
    {   int i_First = 0 , i_Second = 1;
        for (int i = 2; i <= i_Input; ++i)
        {
            i_Result = i_First + i_Second;
            i_First = i_Second;
            i_Second = i_Result;
        }
    }

    cout << i_Result;
    return 0;
}