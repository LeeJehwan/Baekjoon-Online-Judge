#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[25];
void fibo(int num) {
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= num; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[num] << endl;
}
int main() {
	int num;
	cin >> num;
	fibo(num);


}

