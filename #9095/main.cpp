#include <iostream>
using namespace std;
int numCount = 0;
void solve(int sum,int ans){
  if(sum > ans) return;
  if(sum == ans){
    numCount++;
    return ;
  }
  solve(sum+1,ans);
  solve(sum+2,ans);
  solve(sum+3,ans);
}
int main(){
  int testCase;
  cin >> testCase;
  for (int i = 0; i < testCase; i++) {
    int n;
    cin >> n;
    solve(0,n);
    cout << numCount << "\n";
    numCount = 0;
  }
}
