#include <iostream>
//#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,int> > v;
int ans = 0;
int n;
void solve(int index, int sum){
  if(index > n) return;
  if(index == n){
    if(ans < sum){
      ans = sum;
    }
    return;
  }
  solve(index+v[index].first,sum+v[index].second);
  solve(index+1,sum);
}

int main(){
 cin >> n;
 for (int i = 0; i < n; i++) {
   int a,b;
   cin >> a >> b;
   v.push_back(make_pair(a,b));
 }
 solve(0,0);
 cout << ans << '\n';
 return 0;
}
