#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int count = 0;
	int step = 1;
	for (int i = 0; i < n-1; i+=step) {
		if (s[i] == 'E' && s[i + 1] == 'W') {
			step = 2;
			count++;
		}
		step = 1;
	}

	if (count == 0)
		count = 1;
	cout << count << '\n';
}