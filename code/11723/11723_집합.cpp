#include <iostream>
#include <string>
using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int bit = 0;
	while (n--) {
		string man;
		cin >> man;
		if (man == "add") {
			int t;
			cin >> t;
			bit = (bit | (1 << t));
		}
		else if (man == "remove") {
			int t;
			cin >> t;
			bit = (bit & ~(1 << t));
		}
		else if (man == "check") {
			int t;
			cin >> t;
			if ((bit & (1 << t)) == 0) {
				cout << 0 << endl;
			}
			else {
				cout << 1 << endl;
			}
		}
		else if (man == "toggle") {
			int t;
			cin >> t;
			bit = (bit ^ (1 << t));
		}
		else if (man == "all") {
			bit = (1 << 21) - 1;
		}
		else if (man == "empty") {
			bit = 0;
		}

	}
}