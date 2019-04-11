#include <iostream>
using namespace std;

int main() {
	int sum[5] = { 0, };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			int t;
			cin >> t;
			sum[i] += t;
		}
	}
	int max = 0;
	int k;
	for (int i = 0; i < 5; i++) {
		if (max < sum[i]) {
			max = sum[i];
			k = i;
		}
	}
	cout << k + 1 << " " << max << endl;
}