#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


double dist(pair<int, int> p1,pair<int, int> p2) {
	int a = abs(p1.first - p2.first);
	int b = abs(p1.second - p2.second);
	int ret = a * a + b * b;
	return sqrt(ret);
}

int main() {
	vector<pair<int, int>> v(4);
	for (int i = 0; i < 4; i++) {
		cin >> v[i].first >> v[i].second;
	}

	vector<int> p;
	p.push_back(1);
	p.push_back(2);
	p.push_back(3);
	
	vector<int> ans;
	do {
		double t = dist(v[0], v[p[0]]);
		for (int i = 1; i < 3; i++) {
			t += dist(v[p[i - 1]], v[p[i]]);
		}
		ans.push_back((int)t);
	} while (next_permutation(p.begin(), p.end()));

	cout << *min_element(ans.begin(), ans.end()) << endl;
}


