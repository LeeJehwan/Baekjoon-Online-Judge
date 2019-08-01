#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
set<string> s;
int map[5][5];
int dx[4] = { -1, 0, 1 , 0 };
int dy[4] = { 0, -1, 0, 1 };
void dfs(int x, int y, int index, string str) {
	if (index == 5) {
		s.insert(str);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
			continue;

		str += map[nx][ny];
		dfs(nx, ny, index + 1, str);
		str.pop_back();
	}


}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			string str = "";
			str += map[i][j];
			dfs(i, j, 0, str);
		}
	}

	cout << s.size() << endl;
}