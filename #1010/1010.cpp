#include <iostream>
using namespace std;
typedef long long ll;

ll Combination(ll w, ll e)
{
	ll Diff = e - w;
	ll temp = 1;
	if (Diff < w)
		w = Diff;
	for (int i = 0; i < w; i++) {
		temp = temp *(e - i)/(i + 1);
		
	}
	return temp;
}
int main() {
	ll TestCase;
	cin >> TestCase;
	ll West, East;
	for (int i = 0; i < TestCase; i++) {
		cin >> West >> East;
		printf("%d\n", Combination(West, East));
	}
	
}