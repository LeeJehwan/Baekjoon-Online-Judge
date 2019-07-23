#include <iostream>
#include <vector>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> ii;

ll dist(ii p1, ii p2) {
	ll x1 = (p1.first - p2.first);
	ll y2 = (p1.second - p2.second);
	return x1 * x1 + y2 * y2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		vector<ii> v(4);
		for (int i = 0; i < 4; i++) {
			cin >> v[i].first >> v[i].second;
		}
		vector<ll> len;
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				len.push_back(dist(v[i], v[j]));
			}
		}
		sort(len.begin(), len.end());
		if (len[0] == len[1] && len[1] == len[2] && len[2] == len[3]) {
			if (len[4] == len[5]) {
				cout << 1 << endl;
				continue;
			}
		}
		cout << 0 << endl;
	}
}