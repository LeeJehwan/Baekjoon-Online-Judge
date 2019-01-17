#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	priority_queue<int,vector<int>,greater<int>> q;

	int n;
	cin >> n;

	while (n--) {
		int tmp;
		cin >> tmp;

		if (tmp == 0) {
			if (q.empty())
				cout << 0 << endl;
			else {
				cout << q.top() << endl;
				q.pop();
			}

		}
		else {
			q.push(tmp);
		}
	}
}