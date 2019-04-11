#include <iostream>
using namespace std;

int count2 = 0;
void oneNum(int n) {
	int tmp = n % 10;
	n = n / 10;
	int tmp2 = n % 10;
	int dis = tmp2 - tmp;
	while (1) {
		if (n == 0)
			break;
		int tmp = n % 10;
		n = n / 10;
		if (n == 0)
			break;
		int tmp2 = n % 10;
		if (tmp2 - tmp != dis)
			return;
		
	}
	count2++;
}

int main() {
	int num;
	cin >> num;
	if (num < 100) {
		cout << num << endl;
		return 0;
	}
		
	if (num >= 100)
		for (int i = 100; i <= num; i++)
			oneNum(i);
	count2 += 99;
	cout << count2 << endl;

}
