#include <iostream>
#include <cmath>
using namespace std;
int col[15] ={0,};
int cnt = 0;
int n;
bool check(int i){
  int k = 1;
  bool flag = true;
  while (k < i && flag) {
    if(col[i] == col[k] || abs(col[i]-col[k]) == i-k)
      flag = false;
    k++;
  }
  return flag;
}
void solve(int index){
  if(check(index)){
    if(index == n){
      cnt++;
    }
    for (int i = 1; i <= n; i++) {
      col[index+1]= i;
      solve(index+1);     
    }
  }
}
int main(){
  cin >> n;
  solve(0);
  cout << cnt << '\n';
  return 0;
}
