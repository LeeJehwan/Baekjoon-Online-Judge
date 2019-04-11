#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int map[55][55];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int n, m;
int ans = -1;
void cal(vector<int> gen) {
	int h_len = house.size();
	int g_len = gen.size();
	int sum = 0; 

	for (int i = 0; i < h_len; i++) {
		int m_a = 200;
		int hx = house[i].first;
		int hy = house[i].second;
		for (int j = 0; j < g_len; j++) {
			if (gen[j] == 0)
				continue;
			int cx = chicken[j].first;
			int cy = chicken[j].second;
			int dist = abs(hx - cx) + abs(hy - cy);
			m_a = min(dist, m_a);
		}
		sum += m_a;
	}
	if (ans == -1 || ans > sum)
		ans = sum;
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				house.emplace_back(i, j);
			else if (map[i][j] == 2)
				chicken.emplace_back(i, j);
		}
	}

	int c_len = chicken.size();
	
	vector<int> gen(c_len);
	for (int i = 0; i < m; i++)
		gen[i] = 1;

	do {
		cal(gen);
	} while (prev_permutation(gen.begin(), gen.end()));
	
	cout << ans << endl;



}