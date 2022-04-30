#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
using namespace std;

vector<int> vdfs;
vector<int> vbfs;
queue<int> q;
stack<int> st;
int edge[1001][1001];
int visited[1001]={0,};

void bfs(int n, int s){
   visited[s] = 1;
   q.push(s);
   vbfs.push_back(s);
   while(!q.empty()){
     s = q.front();
     q.pop();
     for (int i = 1; i <= n; i++) {
       if(visited[i] == 0 && edge[s][i] == 1 && edge[i][s] == 1){
        vbfs.push_back(i);
        visited[i] = 1;
        q.push(i);
       }
     }
   }
}
void dfs(int n, int s){
  visited[s] = 1;
  vdfs.push_back(s);
  for (int i = 1; i <= n; i++) {
    if(visited[i] == 0 && edge[i][s] && edge[s][i]){
      dfs(n,i);
    }
  }
}
void dfsStack(int n, int s) {
  visited[s] = 1;
  st.push(s);
  while(!st.empty()){
    s = st.top();
    cout << s << " ";
    st.pop();
    for (int i = n; i > 0; i--) {
      if(!visited[i] && edge[s][i] && edge[i][s]) {
        visited[i] = 1;
        st.push(i);
      }
    }
  }
  cout << endl;
}

int main(){
  int n,m,start;
  cin >> n >> m >> start;
  int a,b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    edge[a][b] = 1;
    edge[b][a] = 1;
  }
  dfs(n,start);
  for (int k = 0; k < vdfs.size(); k++) {
    printf("%d ",vdfs[k]);
  }
  printf("\n");
  memset(visited,0,sizeof(visited));
  bfs(n,start);
  for (int j = 0; j < vbfs.size(); j++) {
    printf("%d ",vbfs[j]);
  }
  printf("\n");
  memset(visited,0, sizeof(visited));
  dfsStack(n,start);
  return 0;
}
