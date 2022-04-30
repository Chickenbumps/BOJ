#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int n;
bool check[10];
char arr[20];
vector<string> ans;
bool ok(string num){
  for (int i = 0; i < n; i++) {
    if(arr[i] == '>'){
      if(num[i] < num[i+1]) return false;
    }
    if(arr[i] == '<'){
      if(num[i] > num[i+1]) return false;
    }
  }
  return true;
}
void solve(int index, string num){
  if(index == n + 1){
    if(ok(num)) ans.push_back(num);
    return ;
  }
  for (int i = 0; i < 10; i++) {
    if(check[i])  continue;
    check[i] = true;
    solve(index+1,num+to_string(i));
    check[i] = false;
  }
}
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  solve(0,"");
  auto a = minmax_element(ans.begin(),ans.end());
  cout << *a.second << '\n';
  cout << *a.first <<'\n';
  return 0;
}
