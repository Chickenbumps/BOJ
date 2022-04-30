#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v;
  int temp = 0;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(),v.end());
  int sum = 0;
  int maxSum = 0;
  do{
    sum = 0;
    for(int i=0; i <n-1; i++){
      temp = v[i]-v[i+1];
      if(temp <0) temp *= -1;
      sum += temp; 
    }
    if(maxSum < sum){
      maxSum = sum;
    }
  }while(next_permutation(v.begin(),v.end()));
  
  printf("%d\n",maxSum);

  return 0;
}
