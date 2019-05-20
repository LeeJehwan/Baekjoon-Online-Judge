#include <iostream>
using namespace std;


int number[16];
void run(int t) {
	if (t == 1)
		return;

	for (int i = 0; i < t; i++) {
		number[i] = (number[i] + number[i + 1]) % 10;
	}

	run(t-1);
}

int main() {
	for (int i = 0; i < 16; i++) {
		if (i % 2 == 0)
			scanf("%1d", &number[i]);
	}

	for (int i = 0; i < 16; i++) {
		if (i % 2)
			scanf("%1d", &number[i]);
	}
	run(15);
	cout << number[0] << number[1] << endl;
}