#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[10][10];
int main(){
  int n;
  cin >> n;
  int temp = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> temp;
      arr[i][j] = temp;
    }
  }
  vector<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(i);
  }
  int minSum = 100000000;
  int sum = 0;
  int notgo =0;
  do{
    sum = 0;
    notgo = 0;
    for (int i = 1; i < n; i++) {
      if(arr[v[i-1]][v[i]]==0){
        notgo = 1;
      } 
      sum += arr[v[i-1]][v[i]];
    }
   
    if(notgo == 0 && arr[v[n-1]][v[0]]){
      sum += arr[v[n-1]][v[0]]; 
      minSum = min(minSum,sum);
    }
  }while(next_permutation(v.begin(),v.end()));

  printf("%d\n",minSum);
  return 0;

}
