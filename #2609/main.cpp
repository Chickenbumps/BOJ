#include <iostream>
using namespace std;

int gcd(int m, int n){
	while(n != 0){
		int temp = m % n;
		m = n;
		n = temp;
	}
	return m;
}

int lcm(int m, int n){
	int gcdNum = gcd(m,n);
	return m*n/gcdNum;
}

int main(){
	int a,b;
	cin >> a >> b;
	int g = gcd(a,b);
	int l = lcm(a,b);
	cout << g << '\n' << l;
	return 0;
}
