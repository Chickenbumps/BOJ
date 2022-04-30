#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check(vector<int> &temp, vector<char> &a){
  for (int i = 0; i < a.size(); i++) {
    if(a[i] == '<' && temp[i] > temp[i+1]) {
      return false;
    }
    if(a[i] == '>' && temp[i] < temp[i+1]) {
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  vector<char> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<int> Max(n+1);
  vector<int> Min(n+1);
  for (int i = 0; i <=n ; i++) {
    Min[i] = i;
    Max[i] = 9-i;
  }
  do{
    if(check(Max, arr)){
      break;
    }
  }while(next_permutation(Min.begin(), Min.end()));
  do{
    if(check(Min, arr)){
      break;
    }
  }while(prev_permutation(Max.begin(), Max.end()));
  for (int i = 0; i < Max.size(); i++) {
    cout << Max[i];
  }
  cout << '\n';
  for (int i = 0; i < Min.size(); i++) {
    cout << Min[i];
  }
  cout << '\n';
  return 0;
}
