#include <iostream>
using namespace std;
int main() {
    int i_Input;
    cin >> i_Input;
    double i_Score[i_Input];
    for (int k = 0; k < i_Input; ++k) {
        cin >> i_Score[k];
    }
    double i_MaxScore = i_Score[0];
    for(int i = 1; i < i_Input; i++)
    {
        if(i_MaxScore < i_Score[i])
            i_MaxScore = i_Score[i];
    }
    double i_Sum=0;
    for(int j = 0; j < i_Input; j++) {
        i_Score[j] = (i_Score[j] / i_MaxScore) * 100;
        i_Sum += i_Score[j];
    }
    cout << fixed;
    cout.precision(6);
    cout << i_Sum/i_Input << endl;
    return 0;
}