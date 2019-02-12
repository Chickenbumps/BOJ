#include <iostream>
using namespace std;

int main() {
	char a;
	while (1) {
		a = getchar();
		if (a == EOF)
			break;
		putchar(a);
	}
	return 0;

	/*
	char s[101];
	while(fgets(s)) puts(s);
	*/
}