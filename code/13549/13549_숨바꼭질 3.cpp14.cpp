#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
#define endl '\n'
#define MAX 100000

bool chk[100001];
int dis[100001];
int main() {
	int n, k;
	cin >> n >> k;

	deque<int> q;
	q.push_back(n);
	chk[n] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop_front();
		if (x == k)
			break;

		if (x * 2 <= MAX && chk[x * 2] == false) {
			q.push_front(x * 2);
			chk[x * 2] = true;
			dis[x * 2] = dis[x];
		}
		if (x + 1 <= MAX && chk[x + 1] == false) {
			q.push_back(x + 1);
			chk[x + 1] = true;
			dis[x + 1] = dis[x] + 1;
		}
		if (x - 1 >= 0 && chk[x - 1] == false) {
			q.push_back(x - 1);
			chk[x - 1] = true;
			dis[x - 1] = dis[x] + 1;
		}
	}


	cout << dis[k] << endl;
}