#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
using namespace	std;
#define endl '\n'


int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<int> v(5);
		for (int i = 0; i < 5; i++)
			cin >> v[i];

		sort(v.begin(), v.end());
		if (v[3] - v[1] >= 4)
			cout << "KIN" << endl;
		else
			cout << v[1] + v[2] + v[3] << endl;
	}
}