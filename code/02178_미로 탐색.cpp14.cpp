#include <iostream>
#include <queue>
using namespace std;

char maze[105][105];
int maze_check[105][105];


bool isRange(int x, int y, int n, int m) {
	if (x >= 0 && y >= 0 && x <= n && y <= m)
		return true;
	return false;
}


void solve(int n, int m) {
	int start_x=0, start_y = 0;
	queue <pair<int, int>>q;
	q.push(make_pair(start_x, start_y));
	maze_check[start_x][start_y] = 1;
	while (1) {
		int tmpx = q.front().first;
		int tmpy = q.front().second;
		q.pop();

		//left
		if (isRange(tmpx, tmpy - 1, n, m ))
			if (!maze_check[tmpx][tmpy - 1] && maze[tmpx][tmpy - 1]=='1') {
				q.push(make_pair(tmpx, tmpy - 1));
				maze_check[tmpx][tmpy - 1] = maze_check[tmpx][tmpy] + 1;
				if (tmpx == n && tmpy - 1 == m)
					break;
			}
		//right
		if (isRange(tmpx, tmpy + 1, n, m))
			if (!maze_check[tmpx][tmpy + 1] && maze[tmpx][tmpy + 1]=='1') {
				q.push(make_pair(tmpx, tmpy + 1));
				maze_check[tmpx][tmpy + 1] = maze_check[tmpx][tmpy] + 1;
				if (tmpx == n && tmpy + 1 == m)
					break;
			}
		//up
		if (isRange(tmpx - 1, tmpy, n, m))
			if (!maze_check[tmpx  - 1][tmpy] && maze[tmpx - 1][tmpy]=='1') {
				q.push(make_pair(tmpx - 1, tmpy));
				maze_check[tmpx - 1][tmpy] = maze_check[tmpx][tmpy] + 1;
				if (tmpx - 1 == n && tmpy == m)
					break;
			}
		//down
		if (isRange(tmpx + 1, tmpy, n, m))
			if (!maze_check[tmpx + 1][tmpy] && maze[tmpx + 1][tmpy]=='1') {
				q.push(make_pair(tmpx + 1, tmpy));
				maze_check[tmpx + 1][tmpy] = maze_check[tmpx][tmpy] + 1;
				if (tmpx + 1 == n && tmpy == m)
					break;
			}
	}
	

}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> maze[i];

	solve(n-1,m-1);
	cout << maze_check[n-1][m-1] << endl;

}