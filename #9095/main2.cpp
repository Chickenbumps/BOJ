#include <iostream>
using namespace std;
int dp[10];
void solve(){
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= 10; i++) {
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
  }
}

int main(){
  int testCase;
  cin >> testCase;
  solve();
  for (int i = 0; i < testCase; i++) {
    int n;
    cin >>n;
    cout << dp[n] << '\n';
  }
}
