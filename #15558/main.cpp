#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  char m1[n];
  char m2[n];
  for (int i = 0; i < n; i++) {
    cin >> m1[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> m2[i];
  }
  vector<vector<int> > dist(2, vector<int>(n,-1));
  dist[0][0] = 0;
  vector<pair<int,int> > mindex = {{0,1},{0,-1},{1,k}};
  queue<pair<int,int> > q;
  q.push({0,0});
  bool flag = false;
  while(!q.empty()){
    int whichm = q.front().first;
    int now = q.front().second;
    q.pop();
    for (int i = 0; i < 3; i++) {
      int x = (whichm + mindex[i].first)%2;
      int y = now + mindex[i].second;
      if (y >= n) {
        flag = true;
        break;
      }
      if(y < 0) continue;
      if(dist[x][y] != -1) continue;
      if(x == 0 && m1[y] == '0')  continue;
      if(x == 1 && m2[y] == '0') continue;
      if(y < dist[whichm][now] + 1) continue;
      dist[x][y] = dist[whichm][now] + 1;
      q.push(make_pair(x,y));
    }
    if(flag) break;
  }
  if(flag){
    cout << 1 <<'\n';
  }
  else if(!flag){
    cout << 0 <<'\n';
  }
  return 0;

}
