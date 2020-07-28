#include <iostream>
using namespace std;
int dp[1000001];
int ndp[1000001];
void bottomUp(int x){
  dp[1] = 0;
  for (int i = 2; i <= x; i++) {
    dp[i] = dp[i-1] + 1;
    if(i%3 == 0 && dp[i] > dp[i/3] + 1) dp[i] = dp[i/3] + 1;
    if(i%2 == 0 && dp[i] > dp[i/2] + 1) dp[i] = dp[i/2] + 1;
  }
  cout << dp[x] << '\n';
}

int topDown(int x){
  if(x == 1) return 0;
  if(ndp[x] > 0) return ndp[x];
  ndp[x] = topDown(x-1) + 1;
  if(x%3 == 0){
    int temp = topDown(x/3) + 1;
    if(ndp[x] > temp)  ndp[x] = temp;
  }
  if(x%2 == 0){
    int temp = topDown(x/2) + 1;
    if(ndp[x] > temp)  ndp[x] = temp;
  }
  return ndp[x];
}
int main(){
  int n;
  cin >> n;
  bottomUp(n);
  int ans = topDown(n);
  cout << ans << '\n';
}
