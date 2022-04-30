#include <iostream>
#include <cstring>
using namespace std;
int main(){
  int t;
  cin >> t;
  int num[3] = {1,2,3};
  while(t--){
    int sum;
    cin >> sum;
    long long dist[sum+1];
    memset(dist,0,sizeof(dist));
    dist[0] = 1;
    for (int j = 0; j < 3; j++) {
      for (int i = 1; i <= sum; i++) {
        if (i-num[j] >= 0) {
          dist[i] += dist[i-num[j]];
        }
      }
    }
    cout << dist[sum] << '\n';
  }
  return 0;
}
