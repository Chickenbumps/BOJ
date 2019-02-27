#include <iostream>
using namespace std;

int main() {
    int i_Case;
    cin >> i_Case;
    for (int i = 0; i < i_Case; ++i)
    {
        int i_Student;
        cin >> i_Student;
        int i_Score[i_Student];
        int i_ScoreTotal =0;
        for (int j = 0; j < i_Student; ++j) {
            cin >> i_Score[j];
            i_ScoreTotal +=i_Score[j];
        }
        int i_ScoreAverage = i_ScoreTotal / i_Student;
        double d_Count=0;
        for (int k = 0; k < i_Student; ++k) {
            if(i_ScoreAverage < i_Score[k])
            {
                d_Count++;
            }
        }
        cout << fixed;
        cout.precision(3);
        double d_Ratio = d_Count/ (double)i_Student * 100;
        cout << d_Ratio << "%" << endl;

    }
    return 0;
}