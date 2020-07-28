#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
  int n;
  cin >> n;
  vector<int> v;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
  }

  next_permutation(v.begin(),v.end());
  vector<int> s;
  for (int i = 0; i < n; i++) {
    s.push_back(i+1);
  }
  if(s == v)  cout << -1;
  else  
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
}
