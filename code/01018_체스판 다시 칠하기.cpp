#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char chess[51][51];
string s1 = "WBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBW";
string s2 = "BWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWB";
int ans = 0;
void chk(int x, int y) {
	int sum = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			int t = (i-x) * 8 + (j-y);
			if (s1[t] == chess[i][j])
				sum++;
		}
	}
	ans = max(ans, sum);

	sum = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			int t = (i - x) * 8 + (j - y);
			if (s2[t] == chess[i][j])
				sum++;
		}
	}
	ans = max(ans, sum);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> chess[i][j];
		}
	}

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			chk(i, j);
		}
	}

	cout << 64 - ans << endl;
}