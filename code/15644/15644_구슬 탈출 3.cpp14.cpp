#include <iostream>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <tuple>
#include <map>
#include <string>
using namespace std;
#define endl '\n'

char maze[11][11];
int block[11][11];
int chk[11][11][11][11];
int dx[4] = { -1, 0 , 1, 0 };
int dy[4] = { 0 , -1, 0, 1 };
map<string, pair<string,int>> maaa;


string makestring(int a, int b, int c, int d) {
	string str = "";
	str += to_string(a);
	str += to_string(b); 
	str += to_string(c);
	str += to_string(d);
	return str;
}

void find_route(string str) {
	if (maaa.count(str) == 0)
		return;
	find_route(maaa[str].first);

	if (maaa[str].second == 0)
		cout << "U";
	else if (maaa[str].second == 1)
		cout << "L";
	else if (maaa[str].second == 2)
		cout << "D";
	else if (maaa[str].second == 3)
		cout << "R";

}

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> p(3);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'R')
				p[0] = make_pair(i, j);
			if (maze[i][j] == 'B')
				p[1] = make_pair(i, j);
			if (maze[i][j] == 'O')
				p[2] = make_pair(i, j);
			if (maze[i][j] == '#')
				block[i][j] = -1;
		}
	}
	int lx=0, ly=0;
	memset(chk, -1, sizeof(chk));
	queue<pair<int, int>> q;
	q.push(make_pair(p[0].first, p[0].second));		//push red
	q.push(make_pair(p[1].first, p[1].second));		//push blue
	chk[p[0].first][p[0].second][p[1].first][p[1].second] = 0;
	int ans = -1;
	bool ans_flag = false;

	while (!q.empty()) {
		if (ans_flag)
			break;
		int xr = q.front().first;
		int yr = q.front().second;
		q.pop();
		int xb = q.front().first;
		int yb = q.front().second;
		q.pop();

		if (chk[xr][yr][xb][yb] == 11)
			break;
		

		for (int i = 0; i < 4; i++) {
			bool blue_flag = false;
			bool red_flag = false;
			int n_xr = xr;
			int n_yr = yr;
			int n_xb = xb;
			int n_yb = yb;

			while (1) {		//red 
				if (block[n_xr+dx[i]][n_yr+dy[i]] == -1 || ((n_xr+dx[i]) == n_xb && (n_yr+dy[i]) == n_yb))
					break;
				else {
					n_xr += dx[i];
					n_yr += dy[i];
				}

				if (n_xr == p[2].first && n_yr == p[2].second) {
					red_flag = true;
					break;
				}
			}

			while (1) {		//blue
				if (red_flag && (n_xb + dx[i]) == p[2].first && (n_yb + dy[i]) == p[2].second) {
					blue_flag = true;
					break;
				}

				if (block[n_xb+dx[i]][n_yb+dy[i]] == -1 || ((n_xb +dx[i]) == n_xr && (n_yb+dy[i]) == n_yr))
					break;
				else {
					n_xb += dx[i];
					n_yb += dy[i];
				}

				if (n_xb == p[2].first && n_yb == p[2].second) {
					blue_flag = true;
					break;
				}
			}

			while (1) {		//red 
				if (red_flag)
					break;
				if (block[n_xr + dx[i]][n_yr + dy[i]] == -1 || ((n_xr + dx[i]) == n_xb && (n_yr + dy[i]) == n_yb))
					break;
				else {
					n_xr += dx[i];
					n_yr += dy[i];
				}

				if (n_xr == p[2].first && n_yr == p[2].second) {
					red_flag = true;
					break;
				}
			}


			while (1) {		//blue
				if (blue_flag)
					break;
				if (red_flag && n_xb + dx[i] == p[2].first && n_yb + dy[i] == p[2].second) {
					blue_flag = true;
					break;
				}

				if (block[n_xb + dx[i]][n_yb + dy[i]] == -1 || ((n_xb + dx[i]) == n_xr && (n_yb + dy[i]) == n_yr))
					break;
				else {
					n_xb += dx[i];
					n_yb += dy[i];
				}

				if (n_xb == p[2].first && n_yb == p[2].second) {
					blue_flag = true;
					break;
				}
			}

			if (blue_flag == 0 && red_flag == 1) {
				ans = chk[xr][yr][xb][yb] + 1;
				string now = makestring(n_xr, n_yr, n_xb, n_yb);
				string pre = makestring(xr, yr, xb, yb);
				maaa[now] = make_pair(pre, i);
				lx = n_xb;
				ly = n_yb;
				ans_flag = true;
				break;
			}


			if (blue_flag == 0 && chk[n_xr][n_yr][n_xb][n_yb] == -1) {
				q.push(make_pair(n_xr, n_yr));
				q.push(make_pair(n_xb, n_yb));
				chk[n_xr][n_yr][n_xb][n_yb] = chk[xr][yr][xb][yb] + 1;
				string now = makestring(n_xr, n_yr, n_xb, n_yb);
				string pre = makestring(xr, yr, xb, yb);
				maaa[now] = make_pair(pre, i);
			}
		}
	}

	if (ans > 10 || ans == -1) {
		cout << -1 << endl;
		return 0;
	}

	cout << ans << endl;

	string str = makestring(p[2].first, p[2].second, lx, ly);
	find_route(str);
	cout << endl;
}