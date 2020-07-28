#include <iostream>
#include <queue>
using namespace std;
#define MAX 1000000
bool check[MAX];
int dist[MAX];

int main(){
  int n,k;
  cin >> n >> k;
  dist[n] = 0;
  check[n] = true;
  queue<int> q;
  q.push(n);
  while(!q.empty()){
    int now = q.front();
    q.pop();
    if(2*now < MAX){
      if (check[2*now] == false) {
        q.push(2*now);
        check[2*now] = true;
        dist[2*now] = dist[now] + 1;
      }
    }
    if(now+1 < MAX) {
      if (check[now+1] == false) {
        q.push(now+1);
        check[now+1] = true;
        dist[now+1] = dist[now] + 1;
      }
    }
    if (now-1 >= 0) {
      if (check[now-1] == false) {
        q.push(now-1);
        check[now-1] = true;
        dist[now-1] = dist[now] + 1;
      }
    }
  }
  cout << dist[k] << '\n';
  return 0;
}
