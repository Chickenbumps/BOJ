#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  vector<int> d(n);
  vector<int> ab;
  vector<int> cd;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < n; j++) {
     ab.push_back(a[i]+b[j]);
     cd.push_back(c[i]+d[j]);
   } 
  }
  sort(ab.begin(), ab.end());
  sort(cd.begin(), cd.end());
  ll ans = 0;
  for (int i = 0; i < ab.size(); i++) {
    int num = ab[i];
    auto p = equal_range(cd.begin(), cd.end(), -num);
    ans += p.second - p.first;
  }
  cout << ans << '\n';
  return 0;
}
