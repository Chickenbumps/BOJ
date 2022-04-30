#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
  int n;
  cin >> n;
  long long dist[n+1];
  memset(dist,0,sizeof(dist));
  for (int i = 1; i <= n; i++) {
    dist[i] = dist[i-1] + 1;
    for (int j = 1; j <= i-3; j++) {
      long long now = dist[i-j-2]*(j+1);
      if(now > dist[i]) dist[i] = now;
    }
  }

  cout << dist[n] << '\n';
  return 0;
}
