#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


int main() {
	int num;
	cin >> num;
	getchar();
	for (int j = 0; j < num; j++) {
		char str[81];
		char ch;
		int i = 0;
		do {
			str[i++] = getchar();
		} while (str[i - 1] != '\n');

		str[i - 1] = 0;

		int sum = 0;
		int score = 0;

		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == 'O') {
				sum += ++score;
			}
			if (str[i] == 'X')
				score = 0;
		}
		cout << sum << endl;
	}
}