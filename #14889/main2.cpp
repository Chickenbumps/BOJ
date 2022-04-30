#include <iostream>
#include <vector>
using namespace std;
int dp[20][20];
int solve(int index, vector<int>& first, vector<int>& second, int n){
  if(index == n){
    if(first.size() != n/2) return -1;
    if(first.size() != n/2) return -1;
    int f = 0, s = 0;
    for (int i = 0; i < n/2; i++) {
      for (int j = 0; j < n/2; j++) {
        f += dp[first[i]][first[j]];
        s += dp[second[i]][second[j]];
      }
    }
    int diff = f-s;
    if(diff < 0) diff = -diff;
    return diff;
  }
  if(first.size() > n/2)  return -1;
  if(second.size() > n/2) return -1;
  first.push_back(index);
  int Min = -1;
  int f = solve(index+1, first, second,n);
  if(Min == -1 || (f < Min && f > -1))
    Min = f;
  first.pop_back();

  second.push_back(index);
  int s = solve(index+1, first, second,n);
  if(Min == -1 || (s < Min && s > -1))
    Min = s;
  second.pop_back();
  return Min;
}
int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> dp[i][j];
    }
  }
  vector<int> first,second;
  int ans = solve(0,first,second,n);
  cout << ans << '\n'; 
}
