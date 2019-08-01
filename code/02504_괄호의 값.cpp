#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<pair<char, int>> s;
	stack<pair<int, int>> sa;

	string str;
	cin >> str;
	int ans = 0, tmp = 0;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		char ch = str[i];
		if (ch == '(') {
			s.push({ '(', i });

		}
		else if (ch == '[') {
			s.push({ '[', i });

		}
		else if (ch == ')') {
			if (!s.empty()) {
				auto p = s.top();
				s.pop();
				if (p.first != '(') {
					cout << 0 << endl;
					return 0;
				}

				if (!sa.empty()) {
					if (str[i - 1] == ')' || str[i - 1] == ']') {
						while (1) {
							if (sa.empty()) break;
							auto p2 = sa.top();
							if (p2.second < p.second) break;
							sa.pop();
							tmp += p2.first;
						}
						sa.push({ tmp * 2, p.second });
						tmp = 0;
					}
					else {
						sa.push({ tmp + 2, p.second });
					}
				}
				else {
					sa.push({ tmp + 2, p.second });
				}

			}
			else {
				cout << 0 << endl;
				return 0;
			}
		}
		else if (ch == ']') {
			if (!s.empty()) {
				auto p = s.top();
				s.pop();
				if (p.first != '[') {
					cout << 0 << endl;
					return 0;
				}

				if (!sa.empty()) {
					if (str[i - 1] == ')' || str[i - 1] == ']') {
						while (1) {
							if (sa.empty()) break;
							auto p2 = sa.top();
							if (p2.second < p.second) break;
							sa.pop();
							tmp += p2.first;
						}
						sa.push({ tmp * 3, p.second });
						tmp = 0;
					}
					else {
						sa.push({ tmp + 3, p.second });
					}
				}
				else {
					sa.push({ tmp + 3, p.second });
				}

			}
			else {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	if (s.size() != 0) {
		cout << 0 << endl;
		return 0;
	}
	else {
		while (!sa.empty()) {
			ans += sa.top().first;
			sa.pop();
		}
	}
	cout << ans << endl;


}