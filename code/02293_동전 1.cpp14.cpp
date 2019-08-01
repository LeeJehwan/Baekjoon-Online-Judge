#include <iostream>
using namespace std;

int coin[105];
int dp[10005];

void solve(int len, int money) {	
	dp[0] = 1;
	for (int i = 1; i <= len; i++)
		for (int j = coin[i]; j <= money; j++) 
				dp[j] = dp[j] + dp[j - coin[i]];
}


int main() {
	int num, money;
	cin >> num >> money;

	for (int i = 1; i <= num; i++) 
		cin >> coin[i];

	solve(num, money);
	cout << dp[money] << endl;
}