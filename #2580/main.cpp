#include<iostream>
using namespace std;
int map[9][9];
bool c[10][10];
bool c2[10][10];
bool c3[10][10];
int square(int x, int y) {
  return (x/3)*3+(y/3);
}
bool solve(int z){
  if (z == 81) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << map[i][j] << ' ';
      }
      cout << '\n';
    }
    return true;
  }
  int x = z/9;
  int y = z%9;
  if (map[x][y] != 0) {
    return solve(z+1);
  } else {
      for (int i = 1; i <= 9; i++) {
        if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x,y)][i] == 0) {
          c[x][i] = c2[y][i] = c3[square(x,y)][i] = true;
          map[x][y] = i;
          if (solve(z+1)) {
            return true;
          }
          map[x][y] = 0;
          c[x][i] = c2[y][i] = c3[square(x,y)][i] = false;
        }
      }
  }
  return false;
}
int main(){
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> map[i][j];
      if(map[i][j] != 0){
        c[i][map[i][j]] = true;
        c2[j][map[i][j]] = true;
        c3[square(i,j)][map[i][j]] = true;
      }
    }
  }

  solve(0);
  return 0;

}
