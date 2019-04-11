#include <iostream>
#include <vector>
using namespace std;

int sa[35][12];
int n, m, k;
int ans = -1;
vector<pair<int,int>> h;

bool simul() {
	int x, y;
	for (int i = 1; i <= n; i++) {
		x = i;
		for (int j = 1; j <= m; j++) {

			if (sa[j][x] == 1) {
				x++;
			}
			else if (sa[j][x] == 2) {
				x--;
			}
		}
		if (x != i)
			return false;
	}
	return true;
}

int main() {
	cin >> n >> k >> m;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		sa[x][y] = 1;
		sa[x][y + 1] = 2;
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			if (sa[j][i] != 0 || sa[j][i + 1] != 0)
				continue;
			h.emplace_back(i, j);
		}
	}
	if (simul()) {
		cout << 0 << endl;
		return 0;
	}

	int len = h.size();
	for (int i = 0; i < len; i++) {
		int x1 = h[i].first;
		int y1 = h[i].second;
		if (sa[y1][x1] != 0 || sa[y1][x1] !=0) continue;
		sa[y1][x1] = 1;
		sa[y1][x1 + 1] = 2;
		if (simul()) {
			if (ans == -1 || ans > 1)
				ans = 1;
		}

		for (int j = i + 1; j < len; j++) {
			int x2 = h[j].first;
			int y2 = h[j].second;
			if (sa[y2][x2] != 0 || sa[y2][x2] != 0) continue;
			sa[y2][x2] = 1;
			sa[y2][x2 + 1] = 2;
			if (simul()) {
				if (ans == -1 || ans > 2)
					ans = 2;
			}

			for (int k = j + 1; k < len; k++) {
				int x3 = h[k].first;
				int y3 = h[k].second;
				if (sa[y3][x3] != 0 || sa[y3][x3] != 0) continue;
				sa[y3][x3] = 1;
				sa[y3][x3 + 1] = 2;
				if (simul()) {
					if (ans == -1 || ans > 3)
						ans = 3;
				}
				sa[y3][x3] = 0;
				sa[y3][x3 + 1] = 0;
			}
			sa[y2][x2] = 0;
			sa[y2][x2 + 1] = 0;
		}
		sa[y1][x1] = 0;
		sa[y1][x1 + 1] = 0;
	}
	cout << ans << endl;
}

