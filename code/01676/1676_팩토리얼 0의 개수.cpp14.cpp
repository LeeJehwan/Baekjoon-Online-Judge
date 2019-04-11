#include <iostream>
using namespace std;

int count2 = 0;
int count5 = 0;

void find_div2(int num) {
	while (1) {
		if (num % 2 != 0)
			break;
		if (num % 2 == 0) {
			count2++;
			num = num / 2;
		}
	}
}


void find_div5(int num) {
	while (1) {
		if (num % 5 != 0)
			break;
		if (num % 5 == 0) {
			count5++;
			num = num / 5;
		}
	}
}

int main() {
	int num;
	cin >> num;

	for (int i = 2; i <= num; i++) {
		find_div2(i);
		find_div5(i);
	}
	int ret = count2 >= count5 ? count5 : count2;
	cout << ret << endl;
}