#include <iostream>
#include <vector>
using namespace std;
#define MAX 4000001
int n;
int pn = 0;
vector<int> prime(MAX);
bool check[MAX];
int main(){
  cin >> n;
  for (int i = 2; i <= n; i++) {
    if (check[i] == false) {
      prime[pn++] = i;
      for (int j = i*2; j <= n; j+=i) {
        check[j] = true;
      }
    }
  }
  int right = 0;
  int left = 0;
  int sum = prime[0];
  int cnt = 0;

  while(left <= right && right < n ){
    if(prime[right] == 0)
      break;
    if (sum < n) {
      right++;
      sum += prime[right];
    }else if(sum == n){
      cnt++;
      right++;
      sum += prime[right];
    }else if(sum > n){
      sum-=prime[left];
      left++;
      if(left > right && left < n){
        right = left;
        sum = prime[left];
      }
    }
  }
  cout << cnt << '\n';
  return 0;
}
