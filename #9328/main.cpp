#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;


char map[103][103];
bool check[103][103];
bool key[103];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int main(){
  int t;
  cin >> t;
  while (t--) {
    int h,w;
    cin >> h >> w;
    memset(map,0,sizeof(map));
    for (int i = 2; i < h+2; i++) {
      for (int j = 2; j < w+2; j++) {
        cin >> map[i][j];
      }
    }
    h += 4;
    w += 4;
    for (int i = 0; i < h; i++) {
      map[i][0] = '*';
      map[i][1] = '.';
      map[i][w-2] = '.';
      map[i][w-1] = '*';
    }
    for (int j = 1; j < w-1; j++) {
      map[0][j] = '*';
      map[1][j] = '.';
      map[h-2][j] = '.';
      map[h-1][j] = '*';
    }
    memset(key,false,sizeof(key));
    char temp[103];
    cin >> temp;
    int len = strlen(temp);
    if (temp[0] != '0') {
      for (int i = 0; i < len; i++) {
        key[temp[i] - 'a'] = true;
      }
    }
    int ans = 0;
    memset(check,false,sizeof(check));
    queue<pair<int,int> > q;
    queue<pair<int,int> > door[26];
    q.push(make_pair(1,1));
    check[1][1] = true;
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (check[nx][ny]) continue;
        char w = map[nx][ny];
        if (w == '*') {
          continue;
        }
        check[nx][ny] = true;
        if (w == '.') {
          q.push(make_pair(nx,ny));
        } else if(w == '$') {
            ans+=1;
            q.push(make_pair(nx,ny));
        } else if(w >= 'A' && w <= 'Z') {
            if (key[w-'A']) {
              q.push(make_pair(nx,ny));
            } else{
                door[w-'A'].push(make_pair(nx,ny));
            }
        } else if(w >= 'a' && w <= 'z') {
            q.push(make_pair(nx,ny));
            if (!key[w-'a']) {
              key[w-'a'] = true;
              while (!door[w-'a'].empty()) {
                q.push(door[w-'a'].front());
                door[w-'a'].pop();
              }
            }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
