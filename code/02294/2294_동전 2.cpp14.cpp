#include <iostream>
#include <algorithm>
using namespace std;

int coin[105];
int dp[10005];

#define MAX_COIN 10001

void solve(int len, int money) {
	for (int i = 1; i <= money; i++)
		dp[i] = MAX_COIN;

	for (int i = 1; i <= len; i++) {
		for (int j = coin[i]; j <= money; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[money] == MAX_COIN)
		dp[money] = -1;

}



int main() {
	int num, money;
	cin >> num >> money;
	for (int i = 1; i <= num; i++) 
		cin >> coin[i];
	
	solve(num, money);

	cout << dp[money] << endl;
}