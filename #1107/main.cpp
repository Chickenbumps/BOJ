#include <iostream>
using namespace std;
bool button[10];
int possible(int c) {
  if (c == 0) {
    if (button[0]) {
      return 0;
    } else {
      return 1;
    }
  }
  int len = 0;
  while (c > 0) {
    if (button[c % 10]) {
      return 0;
    }
    len += 1;
    c /= 10;
  }
  return len;
}
int main(){
  int n;
  cin >> n;
  int buttonNum;
  cin >> buttonNum;
  for (int i = 0; i < buttonNum ; i++) {
    int temp;
    cin >> temp;
    button[temp] = true;
  }
  int ans = n- 100;
  if (ans < 0) {
    ans = -ans;
  }
  for (int i = 0; i <= 1000000 ; i++) {
    int c= i;
    int len = possible(c);
    if(len > 0){
      int press = c - n;
      if (press < 0) {
        press = -press;
      }
      if (ans > len + press){
        ans = len + press;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
