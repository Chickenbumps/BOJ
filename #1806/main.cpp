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
  vector<int> len;
  while(left <= right && right < n){
    if(sum < s){
      right++;
      sum += a[right];
    }else if(sum == s){
      len.push_back(right-left+1);
      right++;
      sum+=a[right];
    }else if (sum > s){
      len.push_back(right-left+1);
      sum-=a[left];
      left++;
      if(left > right && left < n) {
       right = left;
       sum = a[right];  
      }
    }
  }
  sort(len.begin(), len.end());
  cout<< len[0] << '\n';
  return 0;
}
