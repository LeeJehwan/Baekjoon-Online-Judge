#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	vector<pair<int, int>> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	int sum = 0;
	for (int i = 0; i < n-1; i++) {
		if (v[i].first == v[i + 1].first)
			sum += abs(v[i].second - v[i + 1].second);
		else
			sum += abs(v[i].first - v[i + 1].first);
	}

	if (v[n-1].first == v[0].first)
		sum += abs(v[n-1].second - v[0].second);
	else
		sum += abs(v[n-1].first - v[0].first);
	cout << sum << endl;
}