#include <iostream>
#include <queue>
#include <deque>
using namespace std;
#define MAX 1000000
bool check[MAX];
int dist[MAX];
int Max = MAX;

int main(){
  int n,m;
  cin >> n >> m;
  check[n] = true;
  dist[n] = 0;
  queue<int> q;
  queue<int> next_q;
  q.push(n);

  while(!q.empty()){
    int now = q.front();
    q.pop();
    if(now*2 < Max) {
      if (check[now*2] == false) {
        q.push(now*2);
        check[now*2] = true;
        dist[now*2] = dist[now];
      }
    }
    if (now-1 >= 0) {
      if (check[now-1] == false) {
        next_q.push(now-1);
        check[now-1] = true;
        dist[now-1] = dist[now] + 1;
      }
    }
    if (now+1 < Max){
      if (check[now+1] == false) {
        next_q.push(now+1);
        check[now+1] = true;
        dist[now+1] = dist[now] + 1;
      }
    }
    if (q.empty()) {
      q = next_q;
      next_q = queue<int>();
    }
  }
  cout << dist[m] << '\n';
  return 0;
}
