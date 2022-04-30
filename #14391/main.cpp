#include <iostream>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int map[4][4];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%1d",&map[i][j]);
    }
  }
  int ans = 0;
  for (int s = 0; s < (1<<(n*m)); s++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int cur = 0;
      for (int j = 0; j < m; j++) {
        int k = i*m+j;
        if ((s&(1<<k)) == 0) {
          cur = cur *10 + map[i][j];
        }
        else {
          sum += cur;
          cur = 0;
        }
      }
      sum += cur;
    }
    for (int j = 0; j < m; j++) {
      int cur = 0;
      for (int i = 0; i < n; i++) {
        int k = i*m+j;
        if ((s&(1<<k)) != 0) {
         cur = cur*10 + map[i][j]; 
        }
        else{
         sum += cur;
         cur = 0;
        }
      }
      sum += cur;
    }
    if(ans < sum) ans = sum;
  }
  cout << ans << '\n';
  return 0;
  
  
}
