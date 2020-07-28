#include <iostream>
using namespace std;
#define MAX 10001

int prime[MAX];
bool check[MAX];
int pn = 0;

int main(){
  int n,m;
  cin >> n >> m;
  for (int i = 2; i <= m; i++) {
    if (check[i] == false) {
      prime[pn++] = i;
      for (int j = 2*i; j <= m; j+=i) {
        check[j] = true;
      }
    }
  }

  int minNum = MAX;
  int sum = 0;
  for (int i = 0 ; i < pn; i++) {
    if (prime[i] >= n) {
      minNum = min(minNum, prime[i]);
      sum += prime[i];
    }
  }
  if(sum == 0) cout << -1;
  else
    cout << sum << '\n' << minNum;
}
