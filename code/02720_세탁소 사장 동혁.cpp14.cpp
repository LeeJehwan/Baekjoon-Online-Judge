#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
using namespace	std;
#define endl '\n'


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int a1 = n / 25;
		n -= a1 * 25;

		int a2 = n / 10;
		n -= a2 * 10;

		int a3 = n / 5;
		n -= a3 * 5;

		int a4 = n;
		cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;

	}
}