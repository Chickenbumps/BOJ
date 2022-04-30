#include <iostream>
#include <cstring>
using namespace std;

int main(){
  int n;
  cin >> n;
  int map[n][n];
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < n; j++) {
     cin >> map[i][j];
   }
  }
  long long dist[100][100];
  memset(dist,0,sizeof(dist));
  dist[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 1; k <= j; k++) {
        if(j-k >=0 && map[i][j-k] == k){
          dist[i][j] += dist[i][j-k];
        }
      }
      for (int k = 1; k <= i; k++) {
        if(i-k >=0 && map[i-k][j] == k){
          dist[i][j] += dist[i-k][j];
        }
      }
    }
  }
  cout << dist[n-1][n-1] <<'\n';
  return 0;
}
