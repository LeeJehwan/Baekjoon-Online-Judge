#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int memo[1000001];
void fibo() {
	int n, m;
	cin >> n >> m;
	memset(memo, 0, sizeof(memo));

	memo[1] = 1;
	memo[2] = 1;
	int i = 3;
	while (1) {
		memo[i] = (memo[i - 1] + memo[i - 2]) % m;
		if (memo[i] == 0 && memo[i-1]==1)
			break;
		i++;
	}
	cout << n << " " << i << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		fibo();
	}
}