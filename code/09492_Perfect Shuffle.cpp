#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;

		queue<string> q1;
		queue<string> q2;

		if (n % 2 == 0) {
			for (int i = 0; i < n / 2; i++) {
				string tmp; 
				cin >> tmp;
				q1.push(tmp);
			}
			for (int i = 0; i < n / 2; i++) {
				string tmp;
				cin >> tmp;
				q2.push(tmp);
			}
			for (int i = 0; i < n / 2; i++) {
				cout << q1.front() << endl;
				cout << q2.front() << endl;
				q1.pop();
				q2.pop();
			}

		}
		else {
			for (int i = 0; i < n / 2 + 1; i++) {
				string tmp;
				cin >> tmp;
				q1.push(tmp);
			}
			for (int i = 0; i < n / 2; i++) {
				string tmp;
				cin >> tmp;
				q2.push(tmp);
			}
			for (int i = 0; i < n / 2; i++) {
				cout << q1.front() << endl;
				cout << q2.front() << endl;
				q1.pop();
				q2.pop();
			}
			cout << q1.front() << endl;
			q1.pop();
		}

	}
}