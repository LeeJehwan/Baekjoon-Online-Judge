#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#define endl '\n'

int p[1000005];
int n, m;
void init() {
	for (int i = 0; i <= n; i++) {
		p[i] = i;
	}
}

int find(int x) {
	if (p[x] == x) {
		return x;
	}
	return p[x] = find(p[x]);
}

void _union(int x, int y) {
	int r1 = find(x);
	int r2 = find(y);
	if (r1 != r2)
		p[r1] = r2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) { //union
			if (b != c)
				_union(b, c);
		}
		else {	//find
			if (find(b) == find(c))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}