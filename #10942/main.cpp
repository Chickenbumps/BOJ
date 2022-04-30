#include <cstdio>
#include <vector>
using namespace std;
vector<int> v(2000);
vector<vector<int> > dist(2000,vector<int>(2000,-1));
int solve(int i, int j){
  if(i==j)  return 1;
  else if(i+1==j){
    if(v[i] == v[j])  return 1;
    return 0;
  }
  if(dist[i][j] >= 0)  return dist[i][j];
  if(v[i] != v[j])  return 0;
  else {
    return dist[i][j] = solve(i+1, j-1);
  }
}
int main(){
  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++) {
    scanf("%d",&v[i]);
  }
  int m;
  scanf("%d",&m);
  for (int i = 0; i < m; i++) {
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",solve(a-1,b-1));
  }
  return 0;
}
