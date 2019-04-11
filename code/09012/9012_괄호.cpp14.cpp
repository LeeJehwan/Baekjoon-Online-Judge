#include <iostream>
#include <stack>
#include <string>
using namespace std;

int solve() {
	stack<char> s;
	string str;
	cin >> str;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] == '(')
			s.push(str[i]);
		else if (str[i] == ')') {
			if (s.empty()) {
				return 0;
			}
			else
				s.pop();
		}
	}
	
	if (s.empty())
		return 1;
	else
		return 0;
}



int main() {
	int t;
	cin >> t;
	while (t--) {
		if (!solve())
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
}