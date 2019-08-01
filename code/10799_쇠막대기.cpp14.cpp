#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int cnt = 0;
	int count = 0;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] == '(')
			cnt++;
		else if (str[i] == ')') {
			if (str[i - 1] == '(') {
				cnt--;
				count += cnt;
			}
			else {
				cnt--;
				count++;
			}
		}
	}
	cout << count << endl;
}