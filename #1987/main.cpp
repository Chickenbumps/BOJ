// 65-90
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int row,col;
int map[20][20];
int dx[] ={1,-1,0,0};
int dy[] ={0,0,1,-1};
bool asc[92]={false,};
int solve(int r, int c){
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    int x = c + dx[i];
    int y = r + dy[i];
    if(x >=0 && y>=0 && x < col && y < row){
      if(asc[map[y][x]] == false){
        asc[map[y][x]] = true;
        int temp = solve(y,x);
        if(temp > cnt)  cnt = temp;
        asc[map[y][x]] = false;
      }
    }
  }
  return cnt + 1;
}



int main(){
  cin >> row >> col;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      char temp;
      cin >> temp;
      map[i][j] = (int)temp;
    }
  }
  asc[map[0][0]] = true;
  int ans = solve(0,0);
  cout << ans <<'\n';
  return 0;
}
