#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <cstdio>
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
		vector<int> v(10);
		for (int i = 0; i < 10; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		cout << v[7] << endl;
	}
}