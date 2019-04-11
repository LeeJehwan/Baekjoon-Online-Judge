#include <iostream>
#include <cmath>
using namespace std;

bool broken[10];

int possible(int a) {
	if (a == 0)
		if (broken[0])
			return 0;
		else
			return 1;
	int len = 0;
	while (a > 0) {
		int t = a % 10;
		if (broken[t])
			return 0;
		len++;
		a /= 10;
	}
	return len;
}

int main() {
	int obj;
	cin >> obj;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		broken[t] = 1;
	}
	
	int min = abs(obj - 100);
	for (int i = 0 ; i <= 1000000; i++) {
		int c = i;
		int tr = possible(c);
		if (tr) {
			int tmp = tr + abs(c - obj);
			if (tmp < min)
				min = tmp;
		}
	}
	cout << min << '\n';

}