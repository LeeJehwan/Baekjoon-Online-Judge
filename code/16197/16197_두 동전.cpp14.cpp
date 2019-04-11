#include <iostream>
#include <vector>
#include <string>
using namespace std;


int dx[4] = { -1 , 0 , 1 ,0 };
int dy[4] = { 0, 1, 0 , -1 };
string str[22];
vector<pair<int, int> > coin;

int ans = -1;
int n, m;

void go(int c1, int c2, int c3, int c4, int idx) {
	if (idx == 11) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nc1 = c1 + dx[i];
		int nc2 = c2 + dy[i];
		int nc3 = c3 + dx[i];
		int nc4 = c4 + dy[i];
		bool coin1 = false;
		bool coin2 = false;
		if (nc1 < 0 || nc1 >= n || nc2 < 0 || nc2 >= m)
			coin1 = true;
		if (nc3 < 0 || nc3 >= n || nc4 < 0 || nc4 >= m)
			coin2 = true;
		if (coin1 && coin2) continue;
		
		if (coin1 == 0 && str[nc1][nc2] == '#') {
			nc1 = c1;
			nc2 = c2;
		}

		if (coin2 == 0 && str[nc3][nc4] == '#') {
			nc3 = c3;
			nc4 = c4;
		}


		if (coin1 || coin2) {
			if(ans == -1 || ans > idx)
				ans = idx;
			return;
		}

		go(nc1, nc2, nc3, nc4, idx + 1);
	}


}


int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (str[i][j] == 'o') {
				coin.emplace_back(i, j);
				str[i][j] = '.';
			}
		}
	}
	int c1 = coin[0].first;
	int c2 = coin[0].second;
	int c3 = coin[1].first;
	int c4 = coin[1].second;

	go(c1, c2, c3, c4, 1);
	cout << ans << endl;


}