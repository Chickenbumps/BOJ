#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin << n;
  vector<int> d(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    d[i] = a[i];
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i] && d[j] +1 > d[i]) {
        
      }
    }

  }
  return 0;

}
