#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int b,c;
  cin >> b >> c;
  int total =0;
  int entry = 0;
  for (int j = 0; j < n; j++) {
    total++;
    entry = v[j]-b;
    if(entry > 0){
      int m = entry / c;
      total += m+1;
      if(entry % c == 0)  total--;
    }
  }

  cout << total << endl;
  return 0;
}
