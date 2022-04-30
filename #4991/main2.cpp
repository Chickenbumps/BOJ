#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
char map[21][21];
int dist[21][21]= {-1,};
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
void bfs(int startX, int startY, int h, int w){
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
        if(map[nx][ny] == 'x'){
          continue;
        }
        else if(dist[nx][ny] == -1){
          q.push(make_pair(nx,ny));
          dist[nx][ny] = dist[x][y] + 1;
        }
      }
    }
  }
}
int main(){
  while(1){
    int h,w;
    cin >> w >> h;
    if(h == 0 && w == 0)  break;
    memset(map,0,sizeof(map));
    vector<pair<int,int> > v(1);
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        char temp;
        cin >> temp;
        map[i][j] = temp;
        if (temp == 'o') {
          v[0] = make_pair(i,j);
        }
        else if(temp == '*') {
          v.push_back(make_pair(i,j));
        }
      }
    }
    int vLen= v.size();
    int dResult[21][21];
    bool flag = true;
    memset(dResult,-1,sizeof(dResult));
    for (int i = 0; i < vLen; i++) {
      memset(dist,-1,sizeof(dist));
      bfs(v[i].first,v[i].second, h, w);
      for (int j = 0; j < vLen; j++) {
        dResult[i][j] = dist[v[j].first][v[j].second];
        if (dResult[i][j] == -1) {
          flag = false;
        }
      }
    }
    if (flag == false){
      cout << -1 << '\n';
      continue;
    } 
    vector<int> dirty(vLen-1);
    for (int i = 0; i < vLen-1; i++) {
      dirty[i] = i + 1;
    }
    int ans = 100000000;
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
