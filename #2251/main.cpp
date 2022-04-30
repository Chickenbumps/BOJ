#include <iostream>
#include <queue>
using namespace std;

bool check[201][201];
bool ans[201];
int from[] = {0, 0, 1, 1, 2, 2,};
int to[] = {1, 2, 0, 2, 0, 1};
int main(){
  int water[3];
  for (int i = 0; i < 3; i++) {
    cin >> water[i];
  }
  int sum = water[2];
  queue<pair<int, int> > q;
  q.push(make_pair(0, 0));
  check[0][0] = true;
  ans[water[2]] = true;
  while (!q.empty()) {
    int now[3];
    now[0] = q.front().first;
    now[1] = q.front().second;
    now[2] = sum - now[0] - now[1];
    q.pop();
    for (int i = 0; i < 6; i++) {
      int next[3] = {now[0],now[1],now[2]};
      next[to[i]] += next[from[i]];
      next[from[i]] = 0;
      if(next[to[i]] >= water[to[i]]) {
        next[from[i]] = next[to[i]] - water[to[i]];
        next[to[i]] = water[to[i]];
      }
      if (!check[next[0]][next[1]]) {
        check[next[0]][next[1]] = true;
        q.push(make_pair(next[0], next[1]));
        if (next[0] == 0) {
          ans[next[2]] = true;
        }
      }
    }
  }
  for (int i = 0; i <= water[2]; i++) {
    if (ans[i]) {
      cout << i << ' ';
    }
  }
  cout << '\n';
  return 0;
}
