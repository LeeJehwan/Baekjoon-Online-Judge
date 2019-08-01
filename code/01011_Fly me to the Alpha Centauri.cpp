#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'

long long dp[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; ; i++) {
		if (i % 2 == 0) {
			dp[i] = dp[i - 1] + i / 2;
		}
		else {
			dp[i] = dp[i - 1] + (i + 1) / 2;
		}
		if (dp[i] > 2200000000)
			break;
	}

	while (t--) {
		int x, y;
		cin >> x >> y;
		int d = y - x;
		for (int i = 1; ; i++) {
			if (dp[i] >= d) {
				cout << i << endl;
				break;
			}
		}
	}

}