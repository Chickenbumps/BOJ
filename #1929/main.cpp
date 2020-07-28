#include <iostream>
using namespace std;
#define MAX 1000001

int pn = 0;
int prime[MAX];
bool check[MAX];

int main(){
  int n,m;
  cin >> n >> m;
  for (int i = 2; i <= m; i++) {
    if(check[i] == false){
      prime[pn++] = i;
      for (int j = 2*i; j <= m; j+=i) {
        check[j] = true;
      }
    }
  }

  for (int i = 0; i < pn; i++) {
    if(prime[i] >= n)
      cout << prime[i] << '\n';
  }
}


