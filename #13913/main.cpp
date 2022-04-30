#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001
int dist[MAX];
int check[MAX];
int cnt[MAX];
vector<int> v(MAX);
vector<int> solve;
void fromTo(int n, int k){
  solve.push_back(k);
  if(n == k)  return;
  fromTo(n,v[k]);
}
int main(){
  int n,k;
  cin >> n >> k;
  dist[n] = 0;
  check[n] = true;
  cnt[n] = 1;
  queue<int> q;
  q.push(n);
  while(!q.empty()){
    int now = q.front();
    q.pop();
    if(2*now < MAX){
      if(check[2*now] == false){
        q.push(2*now);
        check[2*now] = true;
        dist[2*now] = dist[now] + 1;
        v[2*now] = now;
      }
    }
    if(now +1 < MAX){
      if (check[now+1] == false) {
        q.push(now+1);
        check[now+1] = true;
        dist[now+1] = dist[now] + 1;
        v[now+1] = now;
      }
    }
    if(now - 1  >= 0){
      if (check[now-1] == false) {
        q.push(now-1);
        check[now-1] = true;
        dist[now-1] = dist[now] + 1;
        v[now-1] = now;
      }
    }
  }
  cout << dist[k] << '\n';
  fromTo(n,k);
  for (int i = solve.size() - 1; i >= 0; i--) {
    cout << solve[i] << ' ';
  }
  cout << '\n';
  return 0;
}
