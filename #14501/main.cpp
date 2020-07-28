#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
int maxSum = 0;

void solve(vector<pair<int, int> > &v, int day, int sum){
  if(day > n) return ;
  if(day == n){
    if (maxSum < sum) {
      maxSum = sum;
    }
    return;
  }
  solve(v,day+v[day].first,sum +v[day].second);
  solve(v,day+1,sum);
}
int main(){
  cin >> n;
  vector<pair<int, int> > a;
  for (int i = 0; i < n; i++) {
    int t, w;
    cin >> t >> w;
    a.push_back(make_pair(t, w));
  }
  solve(a,0,0);
  cout << maxSum;
}
