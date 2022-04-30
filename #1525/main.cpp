#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int main(){
  int start = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int temp;
      cin >> temp;
      if(temp == 0){
        temp = 9;
      }
      start = start * 10 + temp;
    }
  }
  
  queue<int> q;
  q.push(start);
  map<int,int> d;
  d[start] = 0;
  while(!q.empty()){
    int now = q.front();
    string sNow = to_string(now);
    q.pop();
    int z = sNow.find('9');
    int x = z/3;
    int y = z%3;
    for (int i = 0; i < 4; i++) {
      int mx = x + dx[i];
      int my = y + dy[i];
      if(mx < 3 && mx >= 0 && my <3 && my >= 0){
        string next = sNow;
        swap(next[x*3+y],next[mx*3+my]);
        int num = stoi(next);
        if(d.count(num) == 0) {
          d[num] = d[now] + 1;
          q.push(num);
        }
      }
    }
  }
  if(d.count(123456789) == 0) d[123456789] = -1;
  cout << d[123456789] << '\n';
  return 0;
  
}
