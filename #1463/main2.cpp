// Top-down 방식 
#include <iostream>
using namespace std;
int d[1000001]={0};
int solve(int n){
  if(n == 1) return 0;
  if(d[n] > 0)  return d[n];
  d[n] = solve(n-1) + 1;
  if(n%2 == 0){
    int temp = solve(n/2) + 1;
    if(d[n] > temp) d[n] = temp;
  }
  if(n%3 == 0){
    int temp = solve(n/3) + 1;
    if(d[n] > temp) d[n] = temp;
  }
  return d[n];
}

int main(){
  int x;
  cin >> x;
  int answer = solve(x);
  cout << answer;
}
