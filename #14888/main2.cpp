#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(){
  int n;
  cin >> n;
  int arr[11];
  int arrTemp[11];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arrTemp[i] = arr[i];
  }
  vector<int> v;
  for (int i = 0; i < 4; i++) {
    int temp = 0;
    cin >> temp;
    if(temp != 0){
      for (int j = 0; j < temp; j++) {
        v.push_back(i);
      }
    }
  }

  int minSum = 1000000001;
  int maxSum = -1000000001;
  int sum = 0;
  do{
    sum = 0;
    memcpy(arr,arrTemp,sizeof(arr));
    for (int i = 0; i < n-1; i++) {
      if(v[i] == 0){
        arr[i+1] = arr[i]+arr[i+1];
      }else if(v[i] == 1){
        arr[i+1] = arr[i]-arr[i+1];
      }else if(v[i] == 2){
        arr[i+1] = arr[i]*arr[i+1];
      }else if(v[i] == 3){
        arr[i+1] = arr[i]/arr[i+1];
      }
    }
    sum = arr[n-1];
    minSum = min(minSum,sum);
    maxSum = max(maxSum,sum);
  }while(next_permutation(v.begin(),v.end()));
  printf("%d\n%d",maxSum,minSum);
  return 0;
}
