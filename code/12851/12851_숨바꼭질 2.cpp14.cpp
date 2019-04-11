#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
#define endl '\n'
#define MAX 100000

int dist[100001];
bool chk[100001];
long long cnt[100001];
int main() {
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	chk[n] = true;
	cnt[n] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int next : {x - 1, x + 1, x * 2}) {
			if (next >= 0 && next <= MAX) {
				if (chk[next] == false) {
					q.push(next);
					chk[next] = true;
					dist[next] = dist[x] + 1;
					cnt[next] = cnt[x];
				}
				else if (dist[next] == dist[x] + 1) {
					cnt[next] += cnt[x];
				}
			}
		}
	}
	cout << dist[k] << endl;
	cout << cnt[k] << endl;
}