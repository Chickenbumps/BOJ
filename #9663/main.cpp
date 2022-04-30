#include <iostream>
using namespace std;
int map[15][15] ={0,};
int cnt = 0;
int n;
bool check(int i, int j){
  for (int k = 0; k < n; k++) {
    if(i == k)  continue;
    if(map[k][j] == 1)  return false;
  }
  int tempI = i+1, tempJ = j+1;
  while(tempI < n && tempJ < n){
    if(map[tempI][tempJ] == 1)  return false;
    tempI += 1;
    tempJ += 1;
  }
  tempI = i+1, tempJ = j-1;
  while(tempI < n && tempJ >=0){
    if(map[tempI][tempJ] == 1)  return false;
    tempI += 1;
    tempJ -= 1;
  }
  return true;
}
void solve(int index){
  if(index == n){
    cnt++;
  }
  for (int i = 0; i < n; i++) {
    map[index][i] = 1;
    if(check(index,i)){
      solve(index+1); 
    }
    map[index][i] = 0;
  }
}
int main(){
  cin >> n;
  solve(0);
  cout << cnt << '\n';
  return 0;
}
