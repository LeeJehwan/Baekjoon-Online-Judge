#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x[1005], y[1005];
int main() {
	vector<int> v[2];
	for (int i = 0; i < 3; i++) {
		int a, b;
		cin >> a >> b;
		v[0].push_back(a);
		v[1].push_back(b);
		x[a]++; y[b]++;
	}
	v[0].erase(unique(v[0].begin(), v[0].end()), v[0].end());
	v[1].erase(unique(v[1].begin(), v[1].end()), v[1].end());
	
	if (x[v[0][0]] == 1) {
		cout << v[0][0] << " ";
	}
	else
		cout << v[0][1] << " ";

	if (y[v[1][0]] == 1) {
		cout << v[1][0];
	}
	else
		cout << v[1][1];
}