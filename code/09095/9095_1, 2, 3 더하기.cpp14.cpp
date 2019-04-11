#include <iostream>
using namespace std;

int dp[15];
int main() {
	dp[0] = 1;
	for (int i = 1; i <= 10; i++) 
		for (int j = 1; j <= 3; j++) 
			if (i - j >= 0)
				dp[i] += dp[i - j];
	
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	

}