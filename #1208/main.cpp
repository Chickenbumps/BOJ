#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
  int n,s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m = n-n/2;
  vector<int> first(1<<m);
  for (int i = 0; i < (1<<m); i++) {
    for (int j = 0; j < m; j++) {
      if(i&(1<<j))  first[i]+=a[j];
    }
  }
  vector<int> second(1<<(n-m));
  for (int i = 0; i < (1<<(n-m)); i++) {
    for (int j = 0; j < n-m; j++) {
      if(i&(1<<j))  second[i]+=a[j+m];
    }
  }
  sort(first.begin(), first.end());
  sort(second.begin(), second.end());
  reverse(second.begin(), second.end());
  n = (1<<(n-m));
  m = (1 << m);
  int i = 0;
  int j = 0;
  ll ans = 0;
  while (i < m && j < n) {
    if (first[i] + second[j] == s) {
      ll f1 = 1;
      ll f2 = 1;
      i += 1;
      j += 1;
      while(i < m && first[i] == first[i-1]){
        f1 += 1;
        i += 1;
      }
      while(j < n && second[j] == second[j-1]){
        f2 += 1;
        j +=1;
      }
      ans += f1*f2;
    } else if(first[i] + second[j] < s){
      i+=1;
    } else {
      j+=1;
    }
  }
  if(s == 0) ans -= 1;
  cout << ans << '\n';
  return 0;
}
