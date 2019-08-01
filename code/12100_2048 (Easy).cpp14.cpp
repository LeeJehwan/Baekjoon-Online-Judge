#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

vector<int> gen(int k) {
	vector<int> tmp(5);
	for (int i = 0; i < 5; i++) {
		tmp[i] = (k & 3);
		k >>= 2;
	}
	return tmp;
}

void simul(int (*map)[21], int len, int mode) {
	if(mode == 0){
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				int tx = i;
				int ty = j;
				while (1) {
					tx += dx[mode];
					ty += dy[mode];
					if (tx  < 0 || tx >= len || ty < 0 || ty >= len) {
						break;
					}
					if (map[tx][ty] == 0)
						swap(map[tx][ty], map[tx - dx[mode]][ty - dy[mode]]);
				}
			}
		}

		for (int i = 0; i < len; i++) {
			if (i + 1 == len)
				break;
			for (int j = 0; j < len; j++) {
				if (map[i][j] == map[i + 1][j]) {
					map[i][j] *= 2;
					map[i + 1][j] = 0;
				}
			}
		}
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				int tx = i;
				int ty = j;
				while (1) {
					tx += dx[mode];
					ty += dy[mode];
					if (tx  < 0 || tx >= len || ty < 0 || ty >= len) {
						break;
					}
					if (map[tx][ty] == 0)
						swap(map[tx][ty], map[tx - dx[mode]][ty - dy[mode]]);
				}
			}
		}

	}
	else if (mode == 1) {
		for (int j = 0; j < len; j++) {
			for (int i = 0; i < len; i++) {
				int tx = i;
				int ty = j;
				while (1) {
					tx += dx[mode];
					ty += dy[mode];
					if (tx  < 0 || tx >= len || ty < 0 || ty >= len) {
						break;
					}
					if (map[tx][ty] == 0)
						swap(map[tx][ty], map[tx - dx[mode]][ty - dy[mode]]);
				}
			}
		}

		for (int i = 0; i < len; i ++) {
			if (i + 1 == len)
				break;
			for (int j = 0; j < len; j++) {
				if (map[j][i] == map[j][i+1]) {
					map[j][i] *= 2;
					map[j][i+1] = 0;
				}
			}
		}

		for (int j = 0; j < len; j++) {
			for (int i = 0; i < len; i++) {
				int tx = i;
				int ty = j;
				while (1) {
					tx += dx[mode];
					ty += dy[mode];
					if (tx  < 0 || tx >= len || ty < 0 || ty >= len) {
						break;
					}
					if (map[tx][ty] == 0)
						swap(map[tx][ty], map[tx - dx[mode]][ty - dy[mode]]);
				}
			}
		}
	}
	else if (mode == 2) {
		for (int i = len-1; i >= 0; i--) {
			for (int j = len-1; j >= 0; j--) {
				int tx = i;
				int ty = j;
				while (1) {
					tx += dx[mode];
					ty += dy[mode];
					if (tx  < 0 || tx >= len || ty < 0 || ty >= len) {
						break;
					}
					if (map[tx][ty] == 0)
						swap(map[tx][ty], map[tx - dx[mode]][ty - dy[mode]]);
				}
			}
		}

		for (int i = len-1; i >= 0; i --) {
			if (i == 0)
				break;
			for (int j = len-1; j >=0 ; j --) {
				if (map[i][j] == map[i -1][j]) {
					map[i][j] *= 2;
					map[i -1][j] = 0;
				}
			}
		}
		for (int i = len - 1; i >= 0; i--) {
			for (int j = len - 1; j >= 0; j--) {
				int tx = i;
				int ty = j;
				while (1) {
					tx += dx[mode];
					ty += dy[mode];
					if (tx  < 0 || tx >= len || ty < 0 || ty >= len) {
						break;
					}
					if (map[tx][ty] == 0)
						swap(map[tx][ty], map[tx - dx[mode]][ty - dy[mode]]);
				}
			}
		}

	}
	else if (mode == 3) {
		for (int j = len-1; j >=0 ; j--) {
			for (int i = len-1; i >= 0; i--) {
				int tx = i;
				int ty = j;
				while (1) {
					tx += dx[mode];
					ty += dy[mode];
					if (tx  < 0 || tx >= len || ty < 0 || ty >= len) {
						break;
					}
					if (map[tx][ty] == 0)
						swap(map[tx][ty], map[tx - dx[mode]][ty - dy[mode]]);
				}
			}
		}

		for (int j = len-1; j >= 0; j --) {
			if (j == 0)
				break;
			for (int i = len-1; i >=0; i--) {
				if (map[i][j] == map[i][j-1]) {
					map[i][j] *= 2;
					map[i][j-1] = 0;
				}
			}
		}

		for (int j = len - 1; j >= 0; j--) {
			for (int i = len - 1; i >= 0; i--) {
				int tx = i;
				int ty = j;
				while (1) {
					tx += dx[mode];
					ty += dy[mode];
					if (tx  < 0 || tx >= len || ty < 0 || ty >= len) {
						break;
					}
					if (map[tx][ty] == 0)
						swap(map[tx][ty], map[tx - dx[mode]][ty - dy[mode]]);
				}
			}
		}

	}
}

int main() {
	int n;
	cin >> n;
	int map[21][21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin>>map[i][j];
		}
	}
	int max = -1;
	for (int k = 0; k < (1 << 10); k++) {
		vector<int> now = gen(k);
		int new_map[21][21];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				new_map[i][j] = map[i][j];
			}
		}
		for (int h = 0; h < 5; h++) {
			simul(new_map, n, now[h]);

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (max < new_map[i][j])
						max = new_map[i][j];
				}
			}
		}
	}
	cout << max << endl;

}