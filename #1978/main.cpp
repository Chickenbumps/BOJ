#include <iostream>
using namespace std;

int num[101];
int pn = 0;
bool prime(int n){
  if(n < 2) return false;
  for (int i = 2; i <=n/2 ; i++) {
    if(n%i == 0)  return false;
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    if(prime(num[i])) pn++;
  }
  cout << pn;
}
