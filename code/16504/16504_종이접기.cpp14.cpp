#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

long long arr[1050][1050];
#define endl '\n'
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
		}
	}

	cout << sum << endl;
}