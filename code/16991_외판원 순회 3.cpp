#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
typedef pair<int, int> ii;
vector<ii> v;
double dist[20][20];
double dp[20][100000];
double calc(ii p1, ii p2) {
	int x1 = p1.first - p2.first;
	int x2 = p1.second - p2.second;
	int ret = x1 * x1 + x2 * x2;
	return sqrt(ret);
}

double tsp(int cur, int visit) {
	if (visit == (1 << n) - 1) {
		return dist[cur][0];
	}
	if (dp[cur][visit] != 0) {
		return dp[cur][visit];
	}
	double &ret = dp[cur][visit];
	ret = 1e9;

	for (int next = 0; next < n; next++) {
		if (visit & (1 << next)) continue;
		ret = min(ret, tsp(next, visit | (1 << next)) + dist[cur][next]);
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = calc(v[i], v[j]);
		}
	}

	printf("%.9lf\n", tsp(0, 1));
}