#include <iostream>
using namespace std;

int r,c,n;
int map[101][101] = {0};
int shark[200][5]={0};
void init(){
  cin >> r >> c >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> shark[i][j];
    }
  }
  for (int k = 0; k < n; k++) {
    map[shark[k][0]][shark[k][1]] = 1;
  }
}

// r,c,s,d,z
int main(){
  init();
  int weight = 0;
  for (int i = 1; i <= c; i++) {
    for (int j = 1; j <= r; j++) {
      if(map[j][i] == 1)  weight += shark[4];
    }
  }
}
