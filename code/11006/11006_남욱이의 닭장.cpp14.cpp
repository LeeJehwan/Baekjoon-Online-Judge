#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		int u = m * 2 - n;
		int b = (m * 2 - u * 2) / 2;
		cout << u << " " << b << endl;
	}
}