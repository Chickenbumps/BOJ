#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
  int n;
  cin >> n;
  int map[20][20];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i < (1<<n); i++) {
    vector<int> first;
    vector<int> second;
    for (int j = 0; j < n; j++) {
      if(i&(1<<j)){
        first.push_back(j);
      }
      else {
        second.push_back(j);
      }
    }
    if(first.size() != n/2) continue;
    int t1 = 0;
    int t2 = 0;
    for (int m = 0; m < n/2; m++) {
     for (int k = 0; k < n/2; k++) {
       t1 += map[first[m]][first[k]];
       t2 += map[second[m]][second[k]];
     }
    }
    int diff = t1-t2;
    if(diff < 0)  diff = -diff;
    if(ans > diff) ans = diff;
  }
  cout << ans << '\n';
  
}
