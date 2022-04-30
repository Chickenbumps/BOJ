#include <iostream>
#include <cstring>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  int coinNum[n];
  for (int i = 0; i < n; i++) {
    cin >> coinNum[i];
  }
  long long dist[k+1];
  memset(dist,0,sizeof(dist));
  dist[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j-coinNum[i] >= 0) {
        dist[j] += dist[j-coinNum[i]];
      }
    }
  }
  cout << dist[k] << '\n';
  return 0;
}
