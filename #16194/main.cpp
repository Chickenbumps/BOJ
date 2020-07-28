#include <iostream>
#include <algorithm>
using namespace std;
int d[1001];
void solve(int arr[], int x){
  for (int i = 1; i <= x; i++) {
    d[i] = 1000*10000;
  }
  d[0] = 0;
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <=i; j++) {
      d[i] = min(d[i],d[i-j] + arr[j]);
    }
  }
}

int main() {
  int n;
  cin >> n;
  int p[n+1];
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  solve(p,n);
  cout << d[n] << '\n';
  return 0;
}
