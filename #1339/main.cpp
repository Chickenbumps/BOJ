#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
char dp[400];
int solve(vector<string> &vT, vector<char> &lT, vector<int> &aT){
  int m = lT.size();
  int sum = 0;
  for (int i = 0; i < m; i++) {
    dp[lT[i]] = aT[i];
  }
  for(string s: vT){
    int temp = 0;
    for(char x : s){
      temp = temp * 10 + dp[x];
    }
    sum += temp;
  }
  return sum;
}
int main(){
  int n;
  cin >> n;
  vector<string> v(n);
  vector<char> l;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    for(char x : v[i]){
      l.push_back(x); 
    }
  }

  sort(l.begin(),l.end());
  l.erase(unique(l.begin(),l.end()), l.end());
  int num = l.size();
  vector<int> a;
  for (int i = 9; i > 9-num; i--) {
    a.push_back(i);
  }
  sort(a.begin(),a.end());
  int Max = 0;
  do{
    int temp = solve(v,l,a);
    if(temp > Max) Max = temp;
  }while(next_permutation(a.begin(), a.end()));
  cout << Max << '\n';
  return 0;

}
