#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int arr[13];
vector<int> v;
void go(int cnt, int index, int k){
  if(cnt == 6) {
    for (int i = 0; i < 6; i++) {
      printf("%d ",v[i]);
    }
    printf("\n");
    return ;
  }
  if(index > k - 1){
    return ;
  }
  v.push_back(arr[index]);
  go(cnt+1,index+1,k);
  v.pop_back();
  go(cnt,index+1,k);
}

int main(){
  while(1){
    int k;
    cin >> k;
    if(k == 0)  break;
    memset(arr,0,sizeof(arr));
    for (int i = 0; i < k; i++) {
      cin >> arr[i];
    }
    go(0,0,k);
    printf("\n");
  }
  return 0;
}
