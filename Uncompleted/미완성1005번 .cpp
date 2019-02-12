#include<iostream>

using namespace std;
static int time = 0;
void TimeCalculator(int* BuildTime, int* First, int* Next, int num, int RuleNum);
int main(void) {
	int TestCase;
	cin >> TestCase;
	for (int i = 0; i < TestCase; i++) {
		int BuildNum, RuleNum;
		cin >> BuildNum >> RuleNum;
		int* BuildTime = new int[BuildNum];
		for (int i = 0; i < BuildNum; i++)
			cin >> BuildTime[i];
		int* First = new int[RuleNum];
		int* Next = new int[RuleNum];
		for (int i = 0; i < RuleNum; i++) {
			cin >> First[i] >> Next[i];
		}
		int num;
		cin >> num;
		TimeCalculator(BuildTime, First, Next, num, RuleNum);
	}
	

}

void TimeCalculator(int* BuildTime, int* First, int* Next, int num, int RuleNum) {
	int temp = BuildTime[num - 1];
	if (num == 1) {
		time += temp;
	}

	else {
		for (int i = 0; i < RuleNum; i++) {
			if (Next[i] == num) {
				time += BuildTime[First[i] - 1];
				num = First[i];
				TimeCalculator(BuildTime, First, Next, num, RuleNum);
			}
		}
	}

}