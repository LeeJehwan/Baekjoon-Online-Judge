#include <iostream>
#include <vector>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
#define endl '\n'
typedef long long ll;
long long ccw_vector_area(pair<ll, ll> v1, pair<ll, ll> v2, pair<ll, ll> v3) {
	long long ret = (v1.first*v2.second + v2.first*v3.second + v3.first*v1.second)
		- (v2.first*v1.second + v3.first * v2.second + v1.first * v3.second);

	return ret;
}

int main() {
	int n;
	cin >> n;

	vector<pair<ll, ll>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	long long sum = 0;
	for (int i = 0; i < n - 2; i++) {
		sum += ccw_vector_area(v[0], v[i + 1], v[i + 2]);
	}
	double ans = abs(sum);

	printf("%.1lf\n", ans / 2);
}