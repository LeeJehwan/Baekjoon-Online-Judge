#include <iostream>
#include <algorithm>
using namespace std;

int ball[101];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		fill(ball + a, ball + b + 1, c);
	}
	
	for (int i = 1; i <= n; i++)
		cout << ball[i] << " ";
}