#include <iostream>
#include <vector>

using namespace std;
int arr[20];
int cnt = 0;

void solve(int sum, int index, int goal, int n){
  if(goal == sum && index == n){
    cnt++;
    return ;
  }
  if(goal != sum && index == n){
    return ;
  }
  solve(sum+arr[index],index+1,goal,n);
  solve(sum,index+1,goal,n);
}

int main(){
  int n,s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  solve(0,0,s,n);
  if(s == 0)  cnt--;
  printf("%d\n",cnt);
  return 0;
}
