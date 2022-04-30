#include <stdio.h>
struct page{
  int a;
  int b;
  int *c;
};
int main(){
  struct page p[10] ={1};
  for (int i = 0; i < 10; i++) {
    printf("%d,%d,%d\n",p[i].a,p[i].b,p[i]);
  }
  return 0;
}
