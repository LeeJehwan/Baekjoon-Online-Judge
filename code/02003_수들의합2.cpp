#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int ans = 0;
	int left = 0, right = 0;
	int sum = 0;
	while (1) {
		if (sum == m) {
			ans++;
			sum -= v[left++];
		}
		else if (sum < m) {
			if (right == n)
				break;
			sum += v[right++];
		}
		else if (sum > m) {
			sum -= v[left++];
		}

		if (left == n)
			break;
	}

	cout << ans << endl;
}
