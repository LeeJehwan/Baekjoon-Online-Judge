#include <iostream>
#include <vector>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> ii;

vector<pair<ii, ii>> v;
int pa[3005];
int group[3005];
int n;

int ccw(pair<int, int> v1, pair<int, int> v2, pair<int, int> v3) {
	int ret = (v1.first*v2.second + v2.first*v3.second + v3.first*v1.second)
		- (v2.first*v1.second + v3.first * v2.second + v1.first * v3.second);

	if (ret < 0)
		return -1;
	else if (ret == 0)
		return 0;
	else
		return 1;
}

bool chkIntersection(int line1, int line2) {
	ii A = v[line1].first;
	ii B = v[line1].second;
	ii C = v[line2].first;
	ii D = v[line2].second;

	int tmp1 = ccw(A, B, C) * ccw(A, B, D);
	int tmp2 = ccw(C, D, A) * ccw(C, D, B);

	if (tmp1 == 0 && tmp2 == 0) {
		if (A > B) swap(A, B);
		if (C > D) swap(C, D);

		return A <= D && C <= B;
	}
	return tmp1 <= 0 && tmp2 <= 0;
}

void init() {
	for (int i = 0; i <= n; i++)
		pa[i] = i;
}


int find(int x) {
	if (pa[x] == x)
		return x;
	return pa[x] = find(pa[x]);
}

void _union(int x, int y) {
	int f1 = find(x);
	int f2 = find(y);

	if (f1 < f2) pa[f2] = f1;
	else if (f1 > f2) pa[f1] = f2;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({ {a,b}, {c,d} });
	}

	init();
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (chkIntersection(i - 1, j - 1)) {
				_union(i, j);
			}
		}
	}

	int g_count = 0;
	int g_max = 0;
	for (int i = 1; i <= n; i++) {
		if (pa[i] == i) g_count++;
		group[find(i)]++;
		g_max = max(g_max, group[find(i)]);
	}


	cout << g_count << endl;
	cout << g_max << endl;

}