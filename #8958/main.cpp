#include <iostream>
using namespace std;

int main() {
    char i_OX[81]={0};
    int i_Case;
    int i_Score=0;
    int i_Continue =0;
    cin >> i_Case;
    cin.ignore(1);
    for (int i = 0; i < i_Case; ++i)
    {
        cin.getline(i_OX,81,'\n');
        cin.clear();
        for (int j = 0; j < 81; ++j) {
            if(i_OX[j] != 0)
            {
                if(i_OX[j] =='X')
                {
                    i_Continue = 0;
                }
                else if(i_OX[j] == 'O')
                {
                    i_Continue++;
                    i_Score +=i_Continue;
                }
            }
            else
            {
                break;
            }
        }
        cout << i_Score<< endl;
        i_Continue =0;
        i_Score= 0;
    }
    return 0;
}