#include <iostream>
#include <vector>
#include <string>
using namespace std;
int count(int mask, vector<int> &words){
  int cnt = 0;
  for(int word : words){
    if((word & ((1<<26)-1-mask)) == 0)
      cnt++;
  }
  return cnt;
}
// mask 배운단어 
int solve(int index, int k, int mask, vector<int> words){
  if(k < 0) return 0;
  if(index == 26) return count(mask,words);
  int ans = 0;
  int t1 = solve(index+1, k-1, mask | (1 << index),words);
  if(ans < t1) ans = t1;
  if(index != 'a'-'a' && index != 'n'-'a' && index != 'c'-'a' && index != 't'-'a' && index != 'i'-'a'){
    t1 = solve(index+1, k, mask, words);
    if(ans < t1) ans = t1;
  }
  return ans;
}
int main(){
  int n,k;
  cin >> n >> k;
  vector<int> words(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for(char x : s){
      words[i] |= (1 << (x -'a'));
    }
  }
  cout << solve(0,k,0,words) << '\n'; 

}

