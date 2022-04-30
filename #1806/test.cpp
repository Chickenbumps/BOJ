#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n,s;
  cin>> n >> s;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin>> a[i];
  }
  int right = 0;
  int left = 0;
  int sum = a[0];
  int cnt = 0;
  while(left <= right && right < n){
    if(sum < s){
      sum += a[right];
      right++;
    }else if(sum == s){
      cnt++;
      sum-=a[left];
      left++;
    }else if (sum > s){
      sum-=a[left];
      left++;
      if(left > right && left < n) {
       right = left;
       sum = a[right];  
      }
    }
  }
  cout<< cnt << '\n';
  return 0;
}
