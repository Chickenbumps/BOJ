#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 11000000

int main(){
 int n;
 cin >> n;
 int w[11][11] = {0};
 for (int i = 1; i <= n; i++) {
   for (int j = 1; j <= n; j++) {
     cin >> w[i][j];
   }
 }
 vector<int> v;
 int minScore = MAX;
 int sum = 0;
 for (int k = 1; k <= n; k++) {
   v.push_back(k);
 }

 do{
   sum = 0;
  for (int i = 0; i < n; i++) {
    if(i == n - 1 && w[v[i]][v[0]])
    {
      sum += w[v[i]][v[0]];
      minScore = min(minScore, sum);
    }
    else if(i < n - 1 && w[v[i]][v[i+1]])
    {
      sum += w[v[i]][v[i+1]];
    }
  }
 }while(next_permutation(v.begin(), v.end()));
  cout << minScore;
}
