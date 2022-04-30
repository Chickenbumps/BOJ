#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[501];
int dist[501][501];
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    memset(a,0,sizeof(a));
    memset(dist,0,sizeof(dist));
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      dist[i][i] = a[i];
    }
    for (int i = 0; i < n-1; i++) {
      for (int j = i+1; j < n; j++) {
        int sum = 0;
        for (int x = i; x <= j; x++) {
          sum += a[x];
        }
        for (int k = i; k < j; k++) {
          if(dist[i][j] == 0 || dist[i][j] > dist[i][k] + dist[k+1][j]){
            dist[i][j] = dist[i][k] + dist[k+1][j] + sum;
          }
        }
      }
    }
    cout << dist[0][n-1] << '\n';
  }
  return 0;
}
