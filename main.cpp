#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int num = 0;
int n;
vector<char> v;
vector<int> vIndex;
map<string,int> m;
void solve(string result,int index,int choiceNum){
   if(index > n){
    return ;  
  }
  if(choiceNum >=4 && result.find("WHEE") != std::string::npos){
    int pos = result.find("WHEE");
    if(pos > 0){
      return ;
    }
    string temp = "";
    for(auto p : vIndex)
      temp += p;
    m[temp]++;
    if(m[temp] == 1){
      num++;
    }else{
      return ;
    }
  }
  vIndex.push_back(index);
  solve(result+v[index],index+1,choiceNum+1);
  vIndex.pop_back();
  solve(result,index+1,choiceNum);
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++){
    char temp;
    cin >> temp;
    v.push_back(temp);
  }

  solve("",0,0);
  cout << num % 1000000007;
  return 0;
}