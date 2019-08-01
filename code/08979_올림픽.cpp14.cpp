#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

struct medal {
	int gold;
	int silver;
	int bronze;
	int rank;
	int num;
};


bool cmp(const medal m1, const medal m2) {
	if (m1.gold == m2.gold) {
		if (m1.silver == m2.silver) {
			if (m1.bronze == m2.bronze) {
				return m1.num < m2.num;
			}
			else {
				return m1.bronze > m2.bronze;
			}
		}
		else {
			return m1.silver > m2.silver;
		}
	}
	else {
		return m1.gold > m2.gold;
	}
}


int main() {
	int n, k;
	cin >> n >> k;

	vector<medal> v(n + 1);

	for (int i = 0; i < n; i++) {
		int t; 
		cin >> t;
		cin >> v[t].gold >> v[t].silver >> v[t].bronze;
		v[t].rank = 0;
		v[t].num = t;
	}

	sort(v.begin() + 1, v.end(), cmp);
	v[1].rank = 1;
	for (int i = 2; i <= n; i++) {
		if (i != 1) {
			if (v[i - 1].gold == v[i].gold && v[i - 1].silver == v[i].silver && v[i - 1].bronze == v[i].bronze) {
				v[i].rank = v[i - 1].rank;
			}
			else
				v[i].rank = i;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (v[i].num == k)
			cout << v[i].rank << endl;
	}



}