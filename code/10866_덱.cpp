#include <iostream>
#include <string>	
#include <deque>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque <int> d;
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;

		if (str == "push_back") {
			int t;
			cin >> t;
			d.push_back(t);
		}
		else if (str == "push_front") {
			int t;
			cin >> t;
			d.push_front(t);
		}
		else if (str == "pop_front") {
			if (d.empty())
				cout << -1 << endl;
			else {
				cout << d.front() << endl;
				d.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (d.empty())
				cout << -1 << endl;
			else {
				cout << d.back() << endl;
				d.pop_back();
			}
		}
		else if (str == "size") {
			cout << d.size() << endl;
		}
		else if (str == "empty") {
			cout << d.empty() << endl;
		}
		else if (str == "front") {
			if (d.empty())
				cout << -1 << endl;
			else
				cout << d.front() << endl;
		}
		else if (str == "back") {
			if (d.empty())
				cout << -1 << endl;
			else
				cout << d.back() << endl;
		}
	}
}