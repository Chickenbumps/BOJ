#include <iostream>
using namespace std;
typedef long long ll;

int main(){
  ll m_lInput;
  cin.tie(NULL);
  cin >> m_lInput;
  ll m_lA,m_lB;
  for(int i = 0; i < m_lInput; ++i)
  {
    cin.tie(NULL);
    cin >> m_lA>>m_lB;
    cout << m_lA + m_lB;
    cout << "\n";
  }
  return 0;
}
