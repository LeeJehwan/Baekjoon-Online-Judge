#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <vector>
using namespace	std;
#define endl '\n'

int chk[10001];
char from[10001];
void bfs(int a, int b) {
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		if (tmp == b) {
			return;
		}
		int d = (tmp * 2) % 10000;
		if (chk[d] == -1) {
			q.push(d);
			from[d] = 'D';
			chk[d] = tmp;
		}
		int s = (tmp - 1);
		if (s == -1)
			s = 9999;
		if (chk[s] == -1) {
			q.push(s);
			from[s] = 'S';
			chk[s] = tmp;
		}
		int t1 = tmp / 1000;
		int L = (tmp - t1 * 1000) * 10 + t1;
		if (chk[L] == -1) {
			q.push(L);
			from[L] = 'L';
			chk[L] = tmp;
		}
		int t2 = tmp % 10;
		int R = tmp / 10 + 1000 * t2;
		if (chk[R] == -1) {
			q.push(R);
			from[R] = 'R';
			chk[R] = tmp;
		}

	}
}

void print(int a, int b) {
	if (a == b) {
		return;
	}
	print(a, chk[b]);
	cout << from[b];
}

void run() {
	int a, b;
	cin >> a >> b;
	memset(chk, -1, sizeof(chk));
	memset(from, 0, sizeof(from));
	bfs(a, b);
	print(a, b);
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		run();
	}
}