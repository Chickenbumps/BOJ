#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
char m[11][11];
int num[22];
int sumCheck(int k){
  if(k == 0){
    return 0;
  }
  else if(k > 0){  
    return 1;
  }
  else if(k < 0){  
    return 2;
  }
}
int mCheck(int i, int j){
  if(m[i][j] == 0){
    return 0;
  }
  else if(m[i][j] > 0){
    return 1;
  }
  else if(m[i][j] < 0){
    return 2;
  }
}
bool isOk(vector<int> &v){
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += v[j];
      if(mCheck(i,j) != sumCheck(sum))
        return false;
    }
  }
  return true;
}

void solve(int index, vector<int> &v){
  if(index == n){
    if(isOk(v))
      return ;
  }
  /*for (int i = -10; i < 11; i++) {
    if(v.size() == n) break;
    if(flag[i+10]) continue; 
    flag[i+10] = true;
    v.push_back(i);
    solve(index+1,v);
    flag[i+10] = false;
  }
  */
  v.push_back(num[index]);
  solve(index+1,v);
  v.pop_back();
  solve(index+1,v);
}
int main(){
  cin >> n;
  int s = n*(n+1)/2;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      cin >> m[i][j];
    }
  }
  for (int i = 0; i < 21; i++) {
    num[i] = i-10;
  }
  vector<int> v(4);
  solve(0,v);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  return 0;
}
