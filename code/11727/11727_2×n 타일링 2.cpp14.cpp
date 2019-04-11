#include <iostream>
using namespace std;


int main() {
	int num;
	cin >> num;
	int dp[1005] = { 0, };

	for (int i = 1; i <= num; i++) {
		if (i == 1)
			dp[i] = 1;
		else if (i == 2)
			dp[i] = 3;
		else
			dp[i] = (dp[i - 1] + 2*dp[i - 2])%10007;
	}
	cout << dp[num] << endl;

}