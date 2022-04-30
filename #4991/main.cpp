#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
vector<vector<int> > bfs(vector<string> &loc,int startX, int startY){
  int h = loc.size();
  int w = loc[0].size();
  vector<vector<int> > dist(h, vector<int>(w, -1));
  queue<pair<int,int> > q;
  q.push(make_pair(startX,startY));
  dist[startX][startY] = 0;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < h && nx >= 0 && ny < w && ny >= 0) {
        if(dist[nx][ny] == -1 && loc[nx][ny] != 'x'){
          q.push(make_pair(nx,ny));
          dist[nx][ny] = dist[x][y] + 1;
        }
      }
    }
  }
  return dist;
}
int main(){
  while(1){
    int h,w;
    cin >> w >> h;
    if(h == 0 && w == 0)  break;
    vector<string> loc(h);
    for (int i = 0; i < h; i++) {
      cin >> loc[i];
    }
    vector<pair<int,int> > v(1);
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (loc[i][j] == 'o') {
          v[0] = make_pair(i,j);
        }
        else if(loc[i][j] == '*') {
          v.push_back(make_pair(i,j));
        }
      }
    }
    int vLen= v.size();
    vector<vector<int> > dResult(vLen, vector<int>(vLen));
    bool flag = true;
    for (int i = 0; i < vLen; i++) {
     vector<vector<int> > d = bfs(loc,v[i].first,v[i].second);
      for (int j = 0; j < vLen; j++) {
        dResult[i][j] = d[v[j].first][v[j].second];
        if(dResult[i][j] == -1) {
          flag = false;
        }
      }
    }
    if (flag == false) {
      cout << -1 << '\n';
    }
    vector<int> dirty(vLen-1);
    for (int i = 0; i < vLen-1; i++) {
      dirty[i] = i + 1;
    }
    int ans = -1;
    do{
      int now = dResult[0][dirty[0]];
      for (int i = 0; i < vLen-2; i++) {
        now += dResult[dirty[i]][dirty[i+1]];
      }
      if (ans == -1 || ans > now) {
        ans = now;
      }
    }while(next_permutation(dirty.begin(),dirty.end()));
    cout << ans << '\n';
  }
  return 0;
}
