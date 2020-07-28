#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    v.push_back(i);
  }
  if(k == 1){
    int a;
    cin >> a;
    while(--a){
      next_permutation(v.begin(), v.end());
    }
    for (int i = 0; i < n; i++) {
      cout << v[i] << ' ';
    }
  }
  if(k == 2){
    vector<int> temp;
    int num = 1;
    int tmp;
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      temp.push_back(tmp);
    }
    do{
      if(temp == v){
        cout << num;
        break;
      }
      num++;
    }while(next_permutation(v.begin(), v.end()));
  }
  return 0;
}
