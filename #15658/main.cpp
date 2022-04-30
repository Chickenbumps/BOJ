#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[11];
int maxSum =-1000000001;
int minSum =1000000001;
void solve(int index, int sum, int plus, int minus, int mul, int div){
  if(index == n-1){
    maxSum = max(maxSum,sum);
    minSum = min(minSum,sum);
    return;
  }
  if(index > n-1){
    return;
  }
  if(plus > 0){
    solve(index+1,sum+arr[index+1],plus-1,minus,mul,div);
  }
  if(minus >0){
    solve(index+1,sum-arr[index+1],plus,minus-1,mul,div);
  }
  if(mul>0){
    solve(index+1,sum*arr[index+1],plus,minus,mul-1,div);
  }
  if(div>0){
    solve(index+1,sum/arr[index+1],plus,minus,mul,div-1);
  }
}
int main(){
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int cal[4];
  for (int i = 0; i < 4; i++) {
    cin >> cal[i];
  }
  solve(0,arr[0],cal[0],cal[1],cal[2],cal[3]);
  printf("%d\n%d",maxSum,minSum);
  return 0;
}
