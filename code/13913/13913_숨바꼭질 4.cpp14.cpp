#include <iostream>
#include <queue>
using namespace	std;
#define endl '\n'

int chk[100001];
int dist[100001];
bool isRange(int a) {
	if (a >= 0 && a <= 100000 && chk[a] == 0)
		return true;
	return false;
}

void bfs(int s, int k) {
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int tmp = q.front();
		if (tmp == k) {
			cout << chk[k] << endl;
			return;
		}
		q.pop();
		if (isRange(tmp - 1)) {
			q.push(tmp - 1);
			chk[tmp - 1] = chk[tmp] + 1;
			dist[tmp - 1] = tmp;
		}

		if (isRange(tmp + 1)) {
			q.push(tmp + 1);
			chk[tmp + 1] = chk[tmp] + 1;
			dist[tmp + 1] = tmp;
		}
		if (isRange(tmp * 2)) {
			q.push(tmp * 2);
			chk[tmp * 2] = chk[tmp] + 1;
			dist[tmp * 2] = tmp;
		}
	}
}

void print(int n, int x) {
	if (x == n) {
		cout << x << " ";
		return;
	}
	print(n, dist[x]);
	cout << x << " ";
}


int main() {
	int n, k;
	cin >> n >> k;

	bfs(n, k);
	print(n, k);
	cout << endl;
}