#include <iostream>
using namespace std;

int d[1001];

void solve(int x){
  d[1] = 1;
  d[2] = 3;
  for (int i = 3; i <= x; i++) {
    d[i] = 2*d[i-2] + d[i-1];
    d[i] %= 10007;
  }
}

int main(){
  int n;
  cin >> n;
  solve(n);
  cout << d[n] <<'\n';
}
