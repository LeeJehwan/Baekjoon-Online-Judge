#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'


bool cmp(char s1, char s2) {
	return s1 > s2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;
	int sum = 0;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		sum += str[i] - '0';
	}

	bool flag = true;
	if (sum % 3 != 0) flag = false;

	sort(str.begin(), str.end(), cmp);
	if (str[len - 1] != '0')  flag = false;


	if (flag)
		cout << str << endl;
	else
		cout << -1 << endl;
}