#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

int CycleCheck(ll a, ll b) {
	a = a - (a - (a % 10));
	if (a % 10 == 0)
		return 10;
	int Cycle[5] = { 0,0,0,0,0};
	int index;
	
	for (int i = 0; i < 5; i++) {
		Cycle[i] = (ll)pow(a, i+1)-((ll)pow(a, i+1) -((ll)pow(a, i+1) % 10));
		
		if (i > 0 && Cycle[0] == Cycle[i]) {
			index = i;
			break;
		}
	}
	ll num = b % index;
	if (index == 1)
		return Cycle[0];
	if (num == 0)
		return Cycle[index -1];
	return Cycle[num - 1];
}


int main(void) {
	int TestCase;
	cin >> TestCase;
	ll* A = new ll[TestCase];
	ll* B = new ll[TestCase];
	for (int i = 0; i < TestCase; i++) {
		cin >> A[i] >> B[i];
		cout << CycleCheck(A[i], B[i]) << endl;
	}
	
}