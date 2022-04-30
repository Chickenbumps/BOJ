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
  memset(dist,-1,sizeof(dist));
  dist[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if(j-coinNum[i] >=0 && dist[j-coinNum[i]] != -1){
        if (dist[j] == -1 ||dist[j] > dist[j-coinNum[i]] + 1) {
          dist[j] = dist[j-coinNum[i]] + 1;
        }
      }
    }
  }
  cout << dist[k] << '\n';
  return 0;
}

