#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int,vector<pair<int,int> > > m;
int main(){
  int n;
  cin >> n;
  vector<int> itemPrice;
  vector<int> index;
  for(int i= 0 ; i < n; i++){
    int temp;
    cin >> temp;
    itemPrice.push_back(temp);
    index.push_back(i+1);
  }
  for(int i = 1; i <= n; i++){
    int temp;
    cin >> temp;
    for(int j = 0; j < temp;j++){
      int item,price;
      cin >> item >> price;
      m[i].push_back(make_pair(item,price));
    }
  }
  
  int minPrice = 1e9;
  vector<int> tempPrice(n);
  do{
    int sum = 0;
    for(int i = 0 ; i < n;i++){
      tempPrice[i] = itemPrice[i];
    }
    for(auto p : index){
      sum += tempPrice[p-1];
      for(auto mm: m[p]){
        tempPrice[mm.first-1] -= mm.second;
        if(tempPrice[mm.first-1] <= 0){
          tempPrice[mm.first-1] = 1;
        }
      }
    }
    minPrice = min(minPrice,sum);
  }while(next_permutation(index.begin(),index.end()));

  cout << minPrice;

}
