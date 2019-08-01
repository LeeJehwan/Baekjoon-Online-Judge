#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool map[205][205];
int main() {
	int n, m;
	cin >> n >> m;

	vector<int> gen(n-3);
	gen.push_back(1);
	gen.push_back(1);
	gen.push_back(1);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = true;
		map[y - 1][x - 1] = true;
	}
	int ans = 0;
	do {
		int arr[3];
		int c = 0; 
		for (int i = 0; i < n; i++) {
			if (c == 3)
				break;
			if (gen[i])
				arr[c++] = i;
		}

		if (map[arr[0]][arr[1]] || map[arr[0]][arr[2]] || map[arr[1]][arr[2]])
			continue;
		ans++;
	} while (next_permutation(gen.begin(), gen.end()));

	cout << ans << endl;

}