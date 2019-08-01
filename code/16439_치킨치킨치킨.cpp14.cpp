#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int arr[31][31];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	vector<int> ans(m);
	ans[0] = ans[1] = ans[2] = 1;
	int ans_m = -1;
	do {
		int f[3];
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			if (cnt == 3)
				break;
			if (ans[i] == 1)
				f[cnt++] = i;
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += max({ arr[i][f[0]], arr[i][f[1]], arr[i][f[2]] });
		}
		
		if (ans_m < sum)
			ans_m = sum;
	} while (prev_permutation(ans.begin(), ans.end()));
	cout << ans_m << endl;
}