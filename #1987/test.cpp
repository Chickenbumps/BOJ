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
vector<int> v;
bool check(int r, int c){
  if(asc[map[r-1][c]] == false && r-1 >= 0 && c >= 0) return true;
  if(asc[map[r+1][c]] == false && r+1 < row && c >= 0) return true;
  if(asc[map[r][c-1]] == false && r >= 0 && c-1 >= 0) return true;
  if(asc[map[r][c+1]] == false && r >= 0 && c+1 < col) return true;
  return false;
}
void solve(int r, int c, int index){
  for (int i = 0; i < 4; i++) {
    int x = c + dx[i];
    int y = r + dy[i];
    if(x >=0 && y>=0 && x < col && y < row){
      if(asc[map[y][x]] == false){
        asc[map[y][x]] = true;
        solve(y,x,index);
        asc[map[y][x]] = false;
      }
    }
  }
  if(!check(r,c)){
    v.push_back(index);
    return ;
  }
  /*
  asc[map[r][c]] = true;
  if(asc[map[r-1][c]] == false && r-1 >= 0 && c >= 0){
    solve(r-1,c,index+1);
    asc[map[r-1][c]] = true;
  }
  if(asc[map[r+1][c]] == false && r+1 < row && c >= 0){
    solve(r+1,c,index+1);
    asc[map[r+1][c]] = true;
  }
  if(asc[map[r][c-1]] == false && r >= 0 && c-1 >= 0){
    solve(r,c-1,index+1);
    asc[map[r][c-1]] = true;
  }
  if(asc[map[r][c+1]] == false && r >= 0 && c+1 < col){
    solve(r,c+1,index+1);
    asc[map[r][c+1]] = true;
  }
  */
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
  solve(0,0,1);
  sort(v.begin(),v.end()); 
  cout << v.back() <<'\n';
  return 0;
}
