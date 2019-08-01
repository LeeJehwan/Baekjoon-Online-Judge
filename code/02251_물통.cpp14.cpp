#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define endl '\n'
bool chk[201][201];
bool ans[201];
int from[] = { 0,0,1,1,2,2 };
int to[] = { 1,2,0,2,0,1 };

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int sum = c;
	int cap[3] = { a,b,c };
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	chk[a][b] = true;
	ans[c] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int z = sum - x - y;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int next[3] = { x,y,z };
			next[to[i]] += next[from[i]];
			next[from[i]] = 0;
			if (next[to[i]] >= cap[to[i]]) {
				next[from[i]] = next[to[i]] - cap[to[i]];
				next[to[i]] = cap[to[i]];
			}
			if (!chk[next[0]][next[1]]) {
				chk[next[0]][next[1]] = true;
				q.push({ next[0],next[1] });
				if (next[0] == 0)
					ans[next[2]] = true;
			}
		}
	}
	for (int i = 0; i <= c; i++) {
		if (ans[i])
			cout << i << ' ';
	}

	cout << endl;
}