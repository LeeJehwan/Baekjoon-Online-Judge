#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define endl '\n'
//톱니 2번 , 6번 끼리 만남
//N==0 , S == 1 
int state[10][8];
int top = 4;

void rotate(int t, int dir) {
	if (dir == 1) {
		int tmp = state[t][0];
		state[t][0] = state[t][7];
		state[t][7] = state[t][6];
		state[t][6] = state[t][5];
		state[t][5] = state[t][4];
		state[t][4] = state[t][3];
		state[t][3] = state[t][2];
		state[t][2] = state[t][1];
		state[t][1] = tmp;
	}
	else {
		int tmp = state[t][0];
		state[t][0] = state[t][1];
		state[t][1] = state[t][2];
		state[t][2] = state[t][3];
		state[t][3] = state[t][4];
		state[t][4] = state[t][5];
		state[t][5] = state[t][6];
		state[t][6] = state[t][7];
		state[t][7] = tmp;
	}
}

int main() {
	for (int i = 1; i <= top; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &state[i][j]);
		}
	}

	int k;
	cin >> k;
	vector<pair<int, int>> dir(k);
	for (int i = 0; i < k; i++) {
		cin >> dir[i].first;
		cin >> dir[i].second;
	}

	for (int i = 0; i < k; i++) {
		//left
		int now = dir[i].first;
		int now_dir = dir[i].second;

		int next_dir[10];
		memset(next_dir, 0, sizeof(next_dir));
		next_dir[now] = now_dir;

		for (int h = now; h > 1; h--) {
			if (state[h][6] ^ state[h - 1][2]) {
				next_dir[h - 1] = next_dir[h] * -1;
			}
			else
				break;
		}

		for (int h = now; h < top; h++) {
			if (state[h][2] ^ state[h +1][6]) {
				next_dir[h+1] = next_dir[h] * -1;
			}
			else
				break;
		}

		for (int j = 1; j <= top; j++) {
			if (next_dir[j] != 0) {
				rotate(j, next_dir[j]);
			}
		}
	}


	int ans = state[1][0] + state[2][0] * 2 + state[3][0] * 4 + state[4][0] * 8;
	cout << ans << endl;


}