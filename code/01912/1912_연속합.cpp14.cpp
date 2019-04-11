#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100005];
int dp[100005];

int main() {
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) 
		scanf("%d", &arr[i]);
	dp[1] = arr[1];
	int ret = dp[1];
	for (int i = 1; i <= num; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		ret = max(dp[i], ret);
	}

	cout << ret << endl;

}

