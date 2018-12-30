#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N; // 설탕 kg을 입력받는다.
	int Five, Three = 0;
	int min = 10000, x = 0;

	for (Five = 0; Five <= N/5; Five++) {
		for (Three = 0; Three <= N / 3; Three++) {
			if (N == 5 * Five + 3 * Three) {
				x= Five + Three;
				if (x < min)
					min = x;
			}
		}
	}
	if (min == 10000) {
		cout << -1;
		return 0;
	}

	cout << min;
}