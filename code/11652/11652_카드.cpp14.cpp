#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	int cnt = 1;
	long long max = v[0];
	int max_cnt = cnt;
	for (int i = 1; i < n; i++) {
		if (v[i] == v[i - 1]) {
			cnt++;
		}
		else {
			cnt = 1;
		}
		if (max_cnt < cnt) {
			max = v[i];
			max_cnt = cnt;
		}


	}
	cout << max << endl;
}