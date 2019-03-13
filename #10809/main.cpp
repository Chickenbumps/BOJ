#include <iostream>
#include <string>
using namespace std;
//97  ~  122
int main() {
    int c_Alpa[26];
    for (int j = 0; j < 26; ++j) {
        c_Alpa[j] = -1;
    }
    string s_Name;
    cin >> s_Name;
    for (int i = 0; i < s_Name.length(); ++i) {
        if(c_Alpa[(int)s_Name[i]-97] == -1) {
            c_Alpa[(int)s_Name[i] - 97] = i;
        }
    }

    for (int k = 0; k < 26; ++k) {
        cout << c_Alpa[k] << " ";
    }
    return 0;
}