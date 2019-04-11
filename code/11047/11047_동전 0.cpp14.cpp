#include <iostream>
using namespace std;

int main() {
	int num, money;
	int coin[10] = { 0, };
	cin >> num >> money;
	for (int i = 0; i < num; i++)
		cin >> coin[i];

	int count = 0;
	num = num - 1;
	while (money != 0) {
		int temp = money / coin[num];
		count += temp;
		money = money - temp*coin[num];
		num--;
	}

	cout << count << endl;
}