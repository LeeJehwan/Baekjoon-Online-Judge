#include <iostream>
#include <queue>
using namespace std;

long long max_num = 9876543210;
int main() {
	int n;
	cin >> n;

	queue<long long> q;
	for (int i = 0; i < 10; i++)
		q.push(i);

	int cnt = -1;
	while (!q.empty()) {
		long long x = q.front();
		q.pop();
		cnt++;

		if (cnt == n) {
			cout << x << endl;
			return 0;
		}
		if (x == max_num) {
			cout << -1 << endl;
			return 0;
		}


		int tmp = x % 10;
		for (int i = 0; i < tmp; i++) {
			long long nx = x * 10;
			nx += i;
			q.push(nx);
		}
	}

}