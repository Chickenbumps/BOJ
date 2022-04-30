#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> from(n,-1);
    vector<int> dist(n,-1);
    vector<int> how(n,-1);
    queue<int> q;
    q.push(1%n);
    dist[1%n] = 0;
    how[1%n] = 1;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int i = 0; i <= 1; i++) {
        int next = (cur*10 + i)%n;
        if (dist[next] == -1) {
          dist[next] = dist[cur] + 1;
          from[next] = cur;
          how[next] = i;
          q.push(next);
        }
      }
    }
    if (dist[0] == -1) {
      cout << "BRAK" <<'\n';
    } else {
      vector<int> v;
      int i = 0;
      while(i != -1){
        v.push_back(how[i]);
        i = from[i];
      }
      reverse(v.begin(), v.end());
      for (int i = 0; i < v.size(); i++) {
        cout << v[i];
      }
      cout << '\n';
    }
  }
  return 0;
}
