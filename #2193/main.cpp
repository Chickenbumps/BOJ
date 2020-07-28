#include <iostream>
using namespace std;
long long d[91];
void solve(int x){
  d[1] = 1;
  d[2] = 1;
  if(x > 2){
    for (int i = 3; i <= x; i++) {
      d[i] = d[i-1] + d[i-2];
    }
  }
}
int main(){
  int n;
  cin >> n;
  solve(n);
  cout << d[n] << '\n';
}
