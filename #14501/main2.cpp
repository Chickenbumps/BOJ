#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int> > v;
int n;
int maxSum = 0;
void solve(int index,int pSum){
  if(index == n){
    maxSum = max(pSum,maxSum);
    return;
  }
  if(index > n){
    return;
  }
  solve(index+v[index].first,pSum+v[index].second);
  solve(index+1,pSum);
}
int main(){
  cin >> n;
    
  for (int i = 0; i < n; i++) {
    int t1,t2;
    cin >> t1 >> t2;
    v.push_back(make_pair(t1,t2));
  }
  solve(0,0);
  printf("%d\n",maxSum);
  return 0;
}
