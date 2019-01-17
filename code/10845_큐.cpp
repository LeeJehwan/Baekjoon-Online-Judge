#include <iostream>
#include <queue>
#include <string>
using namespace std;


int main() {
	int n;
	cin >> n;

	queue<int> q;
	while (n--) {
		string str;
		cin >> str;

		if (str == "push") {
			int temp;
			cin >> temp;
			q.push(temp);
		}
		else if (str == "pop") {
			if (!q.empty()) {
				cout << q.front() << endl;
				q.pop();
			}
			else
				cout << -1 << endl;
		}
		else if (str == "size") {
			cout << q.size() << endl;
		}
		else if (str == "empty") {
			if (q.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (str == "front") {
			if (!q.empty()) {
				cout << q.front() << endl;
			}
			else
				cout << -1 << endl;
		}
		else if (str == "back") {
			if (!q.empty()) {
				cout << q.back() << endl;
			}
			else
				cout << -1 << endl;
		}

	}

}
