#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	string s;
	cin >> s;
	int n = s.size();
	int t = 'a' - 'A';
	for (int i = 0; i < n; i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= t;
		else
			s[i] += t;
	}
	cout << s << endl;
}