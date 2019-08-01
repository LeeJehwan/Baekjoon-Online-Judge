#include <iostream>
#include <deque>
using namespace std;

int a[5000005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, L;
	cin >> n >> L;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	deque<int> dq;
	for (int i = 0; i < n; i++) {
		if (!dq.empty()) {
			while (!dq.empty() && a[dq.back()] > a[i]) {
				dq.pop_back();
			}
			dq.push_back(i);
			if (dq.front() < i - L + 1)
				dq.pop_front();
		}
		else {
			dq.push_back(i);
		}
		cout << a[dq.front()] << " ";
	}
	cout << endl;
}