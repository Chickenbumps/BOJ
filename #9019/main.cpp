#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
#define MAX 10000
int check[10001];
char how[10001];
int from[10001];
int dist[10001] = {0,};
vector<char> v(4);

void dslr(int a, int b){
  if(a == b) return;
  dslr(a,from[b]);
  v.push_back(how[b]);
}

void solve(int a, int b){
  queue<int> q;
  q.push(a);
  check[a] = true;
  dist[a] = true;
  from[a] = -1;
  while(!q.empty()){
    int now = q.front();
    q.pop();
    if(now == b)  break;
    int d = 2*now%10000, s = now -1, l = (now%1000)*10 + now/1000, r = (now/10) + (now%10)*1000;
    if(s < 0) {
      s = 9999;
    }
    if(check[d] == false){
      q.push(d);
      how[d] = 'D';
      from[d] = now;
      check[d] = true;
      dist[d] = dist[now] + 1;
    }
    if(check[s] == false) {
      q.push(s);
      how[s] = 'S';
      from[s] = now;
      check[s] = true;
      dist[s] = dist[now] + 1;
    }
    if(check[l] == false) {
      q.push(l);
      how[l] = 'L';
      from[l] = now;
      check[l] = true;
      dist[l] = dist[now] + 1;
    }
    if (check[r] == false) {
      q.push(r);
      how[r] = 'R';
      from[r] = now;
      check[r] = true;
      dist[l] = dist[now] + 1;
    }
  }
  return ;
}

int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a,b;
    cin >> a >> b;
    memset(check,false,sizeof(check));
    memset(from,0,sizeof(from));
    memset(dist,0,sizeof(dist));
    memset(how,0,sizeof(how));
    v.clear();
    solve(a,b);
    dslr(a,b);
    reverse(v.begin(), v.end());
   for(char x : v){
    cout<< x;
   }
   cout << '\n';
  }
  return 0;
}
