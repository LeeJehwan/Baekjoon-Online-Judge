#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>
#include <iomanip>
using namespace std;
#define endl '\n'

int a[51];
int main() {
	int m;
	cin >> m;

	int n = 0;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		n += a[i];
	}

	int k;
	cin >> k;

	double ans = 0;
	for (int i = 0; i < m; i++) {
		double tmp = 1;
		for (int j = 0; j < k; j++) {
			if (a[i] < k) {
				tmp = 0;
				break;
			}
			tmp *= (double)(a[i] - j) / (n - j);
		}
		ans += tmp;
	}

	cout << fixed << setprecision(12) << ans << endl;

}