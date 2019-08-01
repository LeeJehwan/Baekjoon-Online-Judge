#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;
#define endl '\n'

int arr[101];
int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	v[0] = v[1] = v[2] = 1;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int min = m + 1;
	int ans = -1;
	do {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (v[i])
				sum += arr[i];
		}
		if (sum > m)
			continue;
		if (min > m - sum) {
			min = m - sum;
			ans = sum;
		}
	} while (prev_permutation(v.begin(), v.end()));
	cout << ans << endl;


}