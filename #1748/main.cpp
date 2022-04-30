#include <iostream>
#include <math.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int mod = 10;
  int nCount = 1;
  while(1){
    if(n/mod != 0){
      nCount++;
      mod *= 10;
    } else {
      break;
    }
  }
  int ans = 0;
  int temp = 9;
  for (int i = 1; i <= nCount; i++) {
    if(i < nCount && i+1 <= nCount){
      ans += i * temp;
      temp *= 10;
    } else if(i == nCount){
      ans = ans + i * (n+1 - pow(10,i-1));
    }
  }
  cout << ans << '\n';
  return 0;
}
