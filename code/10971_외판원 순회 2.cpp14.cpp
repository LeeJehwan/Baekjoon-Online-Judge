#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cost[11][11];


int tsp(const vector<int> &v, int n) {
	int sum = 0;
	for (int i = 0; i < n-1; i++) {
		if (cost[v[i]][v[i + 1]] == 0)
			return -1;
		sum += cost[v[i]][v[i + 1]];
	}
	if (cost[v[n - 1]][1] == 0)
		return -1;
	else
		sum += cost[v[n - 1]][1];
	return sum;
}



int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cost[i][j];
		}
	}
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}
	int ans = 1000000000;
	do {
		if (v[0] != 1)
			break;
		
		int tmp = tsp(v,n);
		if (ans > tmp && tmp != -1)
			ans = tmp;
	} while (next_permutation(v.begin(), v.end()));
	
	cout << ans << '\n';

}