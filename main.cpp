#include <iostream>
using namespace std;

int gcd(int m, int n){
  while (n !=0) {
    int temp = m % n;
    m = n;
    n = temp;
  }
  return m;
}
int lcm (int m, int n){
  return m*n/gcd(m, n);
}
int main(){
  int a,b,l;
  cin >> a >> b >> l;
  int c;
  int lcmab = lcm(a,b);


}
