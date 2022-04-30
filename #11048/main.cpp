#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int map[n+1][m+1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> map[i][j];
    }
  }
  int dist[n+1][m+1];
  memset(dist,0,sizeof(dist));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dist[i][j] = max(max(dist[i-1][j],dist[i][j-1]),dist[i-1][j-1]) + map[i][j];
    }
  }
  cout << dist[n][m] << '\n';
  return 0;
}
