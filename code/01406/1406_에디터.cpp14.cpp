#include <iostream>
#include <stack> 
#include <string>
using namespace std;

int main() {
	stack<char> s1, s2;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		s1.push(str[i]);

	int n;
	cin >> n;
	while (n--) {
		char c;
		cin >> c;
		if (c =='L') {
			if (!s1.empty()) {
				char temp = s1.top();
				s1.pop();
				s2.push(temp);
			}
		}
		else if (c == 'D') {
			if (!s2.empty()) {
				char temp = s2.top();
				s2.pop();
				s1.push(temp);
			}
		}
		else if (c == 'B') {
			if (!s1.empty())
				s1.pop();
		}
		else if (c == 'P') {
			char temp;
			cin >> temp;
			s1.push(temp);
		}
	}

	while(!s1.empty()) {
		char t = s1.top();
		s1.pop();
		s2.push(t);
	}

	while(!s2.empty()) {
		cout << s2.top();
		s2.pop();
	}
	cout << '\n';

}