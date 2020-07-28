#include <iostream>
using namespace std;

int gcd(int a, int b){
  if(b == 0)
    return a;
  return gcd(b,a%b);
}
int lcm(int a, int b){
  return a*b/gcd(a,b);
}

int main(){
  int testCase;
  cin >> testCase;
  for (int i = 0; i < testCase; i++) { 
    int m,n;
    cin >> m >> n;
    cout << lcm(m, n) << '\n';
  }
  return 0;
}
