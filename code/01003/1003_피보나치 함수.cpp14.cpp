#include <iostream>
using namespace std;

int dp[45][2];


void fib(int num) {
	dp[0][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= num; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;
	while (num--) {
		int num2;
		cin >> num2;
		fib(num2);
		cout << dp[num2][0] << " " << dp[num2][1] << '\n';
	}

}