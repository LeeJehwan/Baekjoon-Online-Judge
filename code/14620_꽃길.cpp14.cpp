#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
int n;
int map[15][15];
int dx[5] = { 0, -1,0,1,0 };
int dy[5] = { 0, 0,-1,0,1 };
int chk[15][15];
vector<int> ans;

bool check(int x, int y) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (chk[nx][ny] || nx < 0 || nx >= n || ny < 0 || ny >= n)
			return false;
	}
	return true;
}
int sum_price(int x, int y) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		sum += map[nx][ny];
	}
	return sum;
}
void visit(int x, int y) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		chk[nx][ny] = 1;
	}
}

void unvisit(int x, int y) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		chk[nx][ny] = 0;
	}
}

void go(int index, int x, int y, int sum) {
	if (index == 3) {
		ans.push_back(sum);
		return;
	}
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check(i, j)) {
				visit(i, j);
				int a = sum_price(i, j);
				go(index + 1, i, j, sum + a);
				unvisit(i, j);
			}
		}
	}

}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	go(0, 0, 0, 0);
	
	cout << *min_element(ans.begin(), ans.end()) << endl;

}