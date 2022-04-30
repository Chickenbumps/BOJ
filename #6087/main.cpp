#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int dist[101][101];
int main(){
  int w,h;
  cin >> w >> h;
  vector<string> map(h);
  for (int i = 0; i < h; i++) {
    cin >> map[i];
  }
  int mx = -1,my = -1,kx = -1,ky = -1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if(map[i][j] == 'C'){
        if(mx == -1){
          mx = i, my = j;
        }else {
          kx = i, ky = j;
        }
      }
    }
  }
  memset(dist,-1,sizeof(dist));
  queue<pair<int,int> > q;
  q.push(make_pair(mx,my));
  dist[mx][my] = 0;
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      while(0 <= nx && nx < h && 0 <= ny && ny < w){
        if(map[nx][ny] == '*') break;
        if(dist[nx][ny] == -1) {
          dist[nx][ny] = dist[x][y] + 1;
          q.push(make_pair(nx,ny));
        }
        nx += dx[i];
        ny += dy[i];
      }
     }
   }
  cout << dist[kx][ky] -1 << '\n';
  return 0;
}

