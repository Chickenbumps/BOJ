#include <iostream>
#include <cstring>
using namespace std;

int a[501];
int dist[501][501];

int solve(int i, int j){
  if(i==j){
    return 0;
  }
  if(dist[i][j] != 0){
    return dist[i][j];
  }
  int sum = 0;
  for (int k = i; k <= j; k++) {
    sum += a[k];
  }
  for (int k = i; k < j; k++) {
    int temp = solve(i,k) + solve(k+1,j) + sum;
    if(dist[i][j] == 0 || dist[i][j] > temp){
      dist[i][j] = temp;
    }
  }
  return dist[i][j];
}
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    memset(dist,0,sizeof(dist));
    memset(a,0,sizeof(a));
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << solve(0,n-1) << '\n';
  }
}
