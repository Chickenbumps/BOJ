#include <iostream>
using namespace std;

int solve(int m, int n, int x, int y){
  int tempX = 1, tempY =1;
  int count = 1;
  bool flag = false;
  while(!flag) {
    if(tempX == x && tempY == y) {
      flag = true;
      break;
    }
    if (tempX < m || tempY < n) {
      count++;
      if(tempX < m) tempX++;
      else if(tempX == m) tempX = 1;
      if(tempY < n) tempY++;
      else if(tempY == n) tempY = 1;
    }
  }
  if(flag){
    return count;
  }else {
    return -1;
  }
}
int main(){
  int testCase;
  cin >> testCase;
  for (int i = 0; i < testCase; i++) {
    int M,N,X,Y;
    cin >> M >> N >> X >> Y;
    int ans = solve(M,N,X,Y);
    cout << ans << '\n';
  }
}
