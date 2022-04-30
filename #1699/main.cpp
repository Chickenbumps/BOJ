#include <iostream>
using namespace std;
int d[100001];
int main(){
  int n;
  cin >> n;
  for (int i = 1; i <=n; i++) {
    int tempN = n;
    int count = 0;
    for (int j = n; j > 0; j--) {
      if(tempN >= j*j){
        while(tempN >= j*j){
          count++;
          tempN -= j*j;
        }
        if(tempN == 0){
          d[n] = count;
          break;
        }
      }
    }
  }
  cout << d[n] <<'\n';
  return 0;
}
