#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n,s;
int ans = 0;
void solve(int index, int sum){
  if(index == n && sum == s){
    ans += 1;
    return;
  }
  if(index == n && sum != s){
    return;
  }
  solve(index+1,sum+v[index]);
  solve(index+1,sum);
}
int main(){
  cin >> n >> s;
  for(int i=0;i<n;i++){
    int temp;
    cin >> temp;
    v.push_back(temp);
  }
  solve(0,0);
  if(s==0) ans -=1;
  cout << ans <<'\n';
  return 0;
}
