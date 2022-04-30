#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int right = 0;
  int left = 0;
  int sum = a[0];
  int count = 0;
  while (left <= right && right < n) {
    if(sum < m) {
      right++;
      sum += a[right];
    }else if (sum == m) {
      count++;
      right++;
      sum += a[right];
    }else if(sum > m) {
      sum -= a[left];
      left++;
      if(left > right && left < n){
        right = left;
        sum = a[right];
      }
    }
  }
  cout << count << '\n';
  return 0;
}
