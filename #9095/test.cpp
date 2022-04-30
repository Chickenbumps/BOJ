#include <iostream>
using namespace std;

int go(int count, int sum, int goal){
  if(sum > goal) return 0;
  if(sum == goal) return 1;
  int totalc = 0;
  for(int i = 1; i <= 3; i++){
    totalc += go(count+1,sum+i,goal);
  }
  return totalc;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    printf("%d\n",go(0,0,n));
  }
}
