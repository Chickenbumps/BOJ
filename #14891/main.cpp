#include <iostream>
using namespace std;
int a[8];
int b[8];
int c[8];
int d[8];
int rot;
pair<int,int> arr[100];
void init(){
  for (int i = 0; i < 8; i++) {
    scanf("%1d",&a[i]);
  }
  for (int i = 0; i < 8; i++) {
    scanf("%1d",&b[i]);
  }
  for (int i = 0; i < 8; i++) {
    scanf("%1d",&c[i]);
  }
  for (int i = 0; i < 8; i++) {
    scanf("%1d",&d[i]);
  }
  scanf("%d",&rot);
  for (int i = 0; i < rot; i++) {
    scanf("%d %d",&arr[i].first,&arr[i].second);
  }
  return ;
}
void rotate(int *tt, int dir){
  int cp[8];
  for (int i = 0; i < 8; i++) {
    cp[i] = tt[i];
  }
  if(dir == 1){
    // 10101111
    //  10101111
    for (int i = 0; i < 7; i++) {
      tt[i+1] = cp[i];
    }
    tt[0] = cp[7];
  }
  else if(dir == -1){
    // 10101111
    //10101111 
    for (int i = 1; i < 8; i++) {
      tt[i-1] = cp[i];
    }
    tt[7] = cp[0];
  }
}
int main(){
  init();
  int ab,bc,cd = 0;
  for (int i = 0; i < rot; i++) {
    if(arr[i].first == 1){
      if(a[2] != b[6]){
        ab = 1;
        if(b[2] != c[6]){
          bc = 1;
          if(c[2] != d[6]){
            cd = 1;
          }
        }
      }
      rotate(a,arr[i].second);
      if(ab == 1) rotate(b,arr[i].second*-1);
      if(bc == 1) rotate(c,arr[i].second);
      if(cd == 1) rotate(d,arr[i].second*-1);
     }
    else if(arr[i].first == 2){
      if(b[6] != a[2]){
        ab = 1;
      }
      if(b[2] != c[6]){
        bc = 1;
        if(c[2] != d[6]){
          cd = 1;
        }
      }
      rotate(b,arr[i].second);
      if(ab == 1) rotate(a,arr[i].second*-1);
      if(bc == 1) rotate(c,arr[i].second*-1);
      if(cd == 1) rotate(d,arr[i].second);
    }
    else if(arr[i].first == 3){
      if(c[2] != d[6]){
        cd = 1;
      }
      if(c[6] != b[2]){
        bc = 1;
        if(b[6] != a[2]){
          ab = 1;
        }
      }
      rotate(c,arr[i].second);
      if(cd == 1) rotate(d,arr[i].second*-1);
      if(bc == 1) rotate(b,arr[i].second*-1);
      if(ab == 1) rotate(a,arr[i].second);
    }
    else if(arr[i].first == 4){
      if(d[6] != c[2]){
        cd = 1;
        if(c[6] != b[2]){
          bc = 1;
          if(b[6] != a[2]){
            ab = 1;
          }
        }
      }
      rotate(d,arr[i].second);
      if(cd == 1) rotate(c,arr[i].second*-1);
      if(bc == 1) rotate(b,arr[i].second);
      if(ab == 1) rotate(a,arr[i].second*-1);
    }
    ab = bc = cd = 0;
  }

  int score = 0;
  if(a[0]==1) score += 1;
  if(b[0]==1) score += 2;
  if(c[0]==1) score += 4;
  if(d[0]==1) score += 8;
  printf("%d\n",score);
  return 0;
}
