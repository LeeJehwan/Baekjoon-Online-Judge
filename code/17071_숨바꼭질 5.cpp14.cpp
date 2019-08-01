#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define endl '\n'

int c_chk[500001];
bool b_chk[500001][2];
vector<int> ans;
int main() {
	int c, b;
	cin >> b >> c;
	memset(c_chk, -1, sizeof(c_chk));
	int nx = c;
	int v = 0;
	while (1) {
		nx += v;
		if (nx > 500000)
			break;
		c_chk[nx] = v;
		v++;
	}
	int max_r = v - 1;
	   	  
	queue<pair<int,int>> q;
	q.push({ b, 0 });
	while (!q.empty()) {
		int x = q.front().first;
		int t = q.front().second;
		q.pop();
		int k = c_chk[x];
		if (k != -1) {
			if (k >= t && k % 2 == t % 2) {
				ans.push_back(k);
				continue;
			}
		}
		if (t > max_r) continue;

		for (auto nx : { x - 1 , x + 1 ,x * 2 }) {
			if (nx >= 0 && nx <= 500000) {
				int nt = t + 1;
				if (nt % 2 == 1) {
					if (b_chk[nx][1] == 0) {
						b_chk[nx][1] = 1;
						q.push({ nx, nt });
					}
				}
				else {
					if (b_chk[nx][0] == 0) {
						b_chk[nx][0] = 1;
						q.push({ nx,nt });
					}
				}
			}
		}
	}
	if (ans.size() == 0) {
		cout << -1 << endl;
	}
	else {
		sort(ans.begin(), ans.end());
		cout << ans[0] << endl;
	}
	return 0;
}