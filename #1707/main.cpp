#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;
vector<int> a[20001];
int color[20001];

void dfs(int v, int c){
  color[v] = c;
  for (int i = 0; i < a[v].size(); i++) {
    int cc = a[v][i];
    if (color[cc] == 0) {
      dfs(cc,3-c);
    }
  }
}

int main(){
  int testCase;
  cin >> testCase;
  for (int t = 0; t < testCase; t++) {
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      a[i].clear();
      color[i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int x,y;
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
      if (color[i] == 0) {
        dfs(i,1);
      }
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      for (int k = 0; k < a[i].size(); k++) {
        int j = a[i][k];
        if (color[i] == color[j]) {
          ok = false;
        }
      }
    }
    cout << (ok ? "YES" : "NO");
  }
  return 0;
}
