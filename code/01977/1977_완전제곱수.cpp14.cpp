#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int arr[10005];
	memset(arr, 0, sizeof(arr));
	int min = 0;
	int sum = 0;
	bool boo = true;
	for (int i = 1; i <= 100; i++)
		arr[i*i] = 1;
	for (int i = n; i <= m; i++) {
		if (arr[i]) {
			sum += i;
			if (boo) {
				min = i;
				boo = false;
			}
		}
	}
	if (min == 0) {
		cout << -1 << endl;
		return 0;
	}

	cout << sum << endl;
	cout << min << endl;
}