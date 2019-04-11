#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int arr[100001];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int target;
	cin >> target;
	sort(arr, arr + n);

	int l = 0, r = n-1;

	int ans = 0;
	while (1) {
		if (l == r) break;

		int tmp = arr[l] + arr[r];
		if (tmp < target)
			l++;
		else if (tmp > target)
			r--;
		else {
			ans++;
			r--;
		}

	}
	cout << ans << endl;
}