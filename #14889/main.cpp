#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int> > v(n,vector<int>(n,0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }
  vector<int> b(n);
  for (int i = 0; i < n/2; i++) {
    b[i] = 1;
  }
  sort(b.begin(), b.end());
  int Min = 1000000000;
  do{
    vector<int> first, second;
    for (int i = 0; i < n; i++) {
      if(b[i] == 0) first.push_back(i);
      if(b[i] == 1) second.push_back(i);
    }
    int fSum = 0,sSum = 0;
    for (int i = 0; i < n/2; i++) {
      for (int j = 0; j < n/2; j++) {
        if(i == j)  continue;
        fSum += v[first[i]][first[j]];
        sSum += v[second[i]][second[j]];
      }
    }
    int diff = fSum-sSum;
    if(diff< 0) diff = -diff;
    if(Min > diff)  Min = diff;
  }while(next_permutation(b.begin(),b.end()));
  cout << Min << '\n';
  return 0;
}
