#include <iostream>

using namespace std;

int countNum = 0;
void go(int sum, int goal){
  if(goal == sum) {
    countNum++;
    return ;
  }
  if(goal < sum) {
    return ;
  }
  go(sum+1,goal);
  go(sum+2,goal);
  go(sum+3,goal);
}

int main(){
  int testCase;
  cin >> testCase;
  for (int i = 0; i < testCase; i++) {
    int n;
    cin >> n;
    go(0,n);
    printf("%d\n",countNum);
    countNum = 0;
  }
  return 0;
}
