#include <iostream>
using namespace std;
#define Mod 1000000000;
typedef long long ll;
int d[101][10];
void solve(int x){
  for (int i = 1; i <= 9; i++) {
    d[1][i] = 1;
  }
  for (int i = 2; i <= x; i++) {
    for (int j = 0; j <= 9; j++) {
      d[i][j] = 0;
      if(j-1 >= 0) d[i][j] += d[i-1][j-1];
      if(j+1 <= 9) d[i][j] += d[i-1][j+1];
      d[i][j] %= Mod;
    }
  }
}
int main(){
  int n;
  cin >> n;
  solve(n);
  ll ans = 0;
  for (int i = 0; i < 10; i++) {
    ans += d[n][i];
  }
  cout << ans << '\n';
  return 0;
}
