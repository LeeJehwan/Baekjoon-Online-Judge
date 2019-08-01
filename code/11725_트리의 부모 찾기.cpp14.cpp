#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'


vector<int> v[100001];
bool chk[100001];
vector<int> p[100001];
void bfs(int start) {
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		chk[tmp] = true;
		int len = v[tmp].size();
		for (int i = 0; i < len; i++) {
			int y = v[tmp][i];
			if (!chk[y]) {
				p[y].push_back(tmp);
				q.push(y);
			}
		}
	}
}


int main(){
	int n;	
	cin >> n;

	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	bfs(1);

	for (int i = 2; i <= n; i++) {
		cout << p[i][0] << endl;
	}
}