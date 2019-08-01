#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0 ,1 };
int main() {
	int s = 0;
	for (int i = 0; i < 9; i++) {
		int t;
		cin >> t;
		if (t == 0)
			t = 9;
		s = 10 * s + t;
	}
	queue<int> q;
	q.push(s);
	map<int, int> dist;
	dist[s] = 0;
	while (!q.empty()) {
		int t = q.front();
		string now = to_string(t);
		if (now == "123456789")
			break;
		q.pop();

		int z = now.find('9');
		int x = z / 3;
		int y = z % 3;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				string next = now;
				swap(next[nx * 3 + ny], next[z]);
				int ne = stoi(next);
				if (dist.count(ne) == 0) {
					dist[ne] = dist[t] + 1;
					q.push(ne);
				}
			}

		}

	}

	if (dist.count(123456789) == 0)
		cout << -1 << endl;
	else
		cout << dist[123456789] << endl;



}