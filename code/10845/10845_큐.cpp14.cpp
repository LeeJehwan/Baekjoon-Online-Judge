#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	queue<int> q;
	while (t--) {
		string s;
		cin >> s;
		if (s == "push") {
			int t;
			cin >> t;
			q.push(t);
		}
		else if (s == "pop") {
			if (q.empty())
				cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (s == "size") {
			cout << q.size() << endl;
		}
		else if (s == "empty") {
			cout << q.empty() << endl;
		}
		else if (s == "front") {
			if (q.empty())
				cout << -1 << endl;
			else {
				cout << q.front() << endl;
			}
		}
		else if (s == "back") {
			if (q.empty())
				cout << -1 << endl;
			else {
				cout << q.back() << endl;
			}
		}

	}
}