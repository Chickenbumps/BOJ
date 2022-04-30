#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
  ll t;
  cin >> t;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  vector<int> aP;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += a[j];
      aP.push_back(sum);
    }
  }
  vector<int> bP;
  for (int i = 0; i < m; i++) {
    int sum = 0;
    for (int j = i; j < m; j++) {
      sum += b[j];
      bP.push_back(sum);
    }
  }
  sort(aP.begin(), aP.end());
  sort(bP.begin(), bP.end());
  ll cnt = 0;
  for (int i = 0; i < aP.size(); i++) {
    auto p = equal_range(bP.begin(),bP.end(),t-aP[i]);
    cnt += p.second - p.first;
  }
  cout << cnt << '\n';
  return 0;
}
