#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int arr[7];
		int arr2[7];
		int min_e = 101;
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			cin >> arr[i];
			if (arr[i] % 2 == 0) {
				sum += arr[i];
				min_e = min(min_e, arr[i]);
			}
		}
		cout << sum << " " << min_e << endl;
	}
}