#include <iostream>
#include <algorithm>
using namespace std;


int main(){
  int m[9];
  int sum = 0;
  for (int i = 0; i < 9; i++) {
    cin >> m[i];
    sum += m[i];
  }
  sort(m,m+9);
  for (int i = 0; i < 9; i++) {
    for (int j = i+1; j < 9; j++) {
      if (sum - m[i] - m[j] == 100) {
       for (int k = 0; k < 9 ; k++) {
          if(k != i && k != j)
            cout << m[k] << '\n';
       }
       return 0;
      }
    }
  }
  return 0;
}
