#include <iostream>
using namespace std;
typedef long long ll;
int d[1001][10];

void solve(int x){
  for (int i = 0; i <= 9; i++) {
    d[1][i] = 1;
  }
  for (int i = 2; i <= x; i++) {
    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k <= j; k++) {
        d[i][j] += d[i-1][k];
        d[i][j] %= 10007;
      }
    }
  }
}
int main(){
  int n;
  cin >> n;
  solve(n);
  ll ans = 0;
  for (int i = 0; i <= 9; i++) {
    ans += d[n][i];
  }
  ans %= 10007;
  cout << ans << '\n';

}
