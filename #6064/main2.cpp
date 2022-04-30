#include <iostream>
using namespace std;

int main(){
  int testCase;
  cin >> testCase;
  for (int i = 0; i < testCase; i++){
    int m,n,x,y;
    cin >> m >> n >> x >> y;
    x -= 1;
    y -= 1;
    bool flag = false;
    for (int i = x; i <=m*n; i+=m) {
      if (i%n == y) {
        cout << i+1 << '\n';
        flag = true;
        break;
      }
    }
    if(!flag) cout << -1 <<'\n';
  }
  return 0;
}
