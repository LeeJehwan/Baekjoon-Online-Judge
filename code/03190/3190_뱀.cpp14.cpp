#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int dx[4] = { 0,1,0,-1 }; //RDLU
int dy[4] = { 1,0,-1,0 };
//D(++) L(--)

int map[101][101];
int main() {
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			map[i][j] = -3;
		}
	}

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = -1;
		}
	}

	int apple; 
	cin >> apple;
	for (int i = 0; i < apple; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = -2;
	}
	
	int dir_num;
	cin >> dir_num;
	vector<pair<int, char>> v(dir_num);
	for (int i = 0; i < dir_num; i++) {
		int time;
		char dir;
		cin >> time >> dir;
		v[i] = make_pair(time, dir);
	}

	int time = 1;
	int len = 1;
	int now_dir = 0;
	int now_x = 1;
	int now_y = 1;
	int now_v = 0;
	map[1][1] = 0;
	while (1) {
		now_x = now_x + dx[now_dir];
		now_y = now_y + dy[now_dir];

		if (map[now_x][now_y] == -3)
			break;
		else if (map[now_x][now_y] == -2) {
			map[now_x][now_y] = time;
			len++;
		}
		else if (map[now_x][now_y] == -1) {
			map[now_x][now_y] = time;
		}
		else {
			if (time - len > map[now_x][now_y])
				map[now_x][now_y] = time;
			else
				break;
		}

		if (now_v != dir_num) {
			if (time == v[now_v].first) {
				if (v[now_v].second == 'D') {
					now_dir = (now_dir + 1) % 4;
				}
				else {
					now_dir = (now_dir - 1);
					if (now_dir == -1)
						now_dir = 3;
				}
				now_v++;
			}
		}
		time++;

	}

	cout << time << endl;

}