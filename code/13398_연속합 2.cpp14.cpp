#include <iostream>
#include <algorithm>
using namespace std;

int dp1[100001];
int dp2[100001];
int main() {
	int n;
	cin >> n;

	int arr[100001];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp1[1] = arr[1];
	for (int i = 2; i <= n; i++) 
		dp1[i] = max(dp1[i - 1] + arr[i], arr[i]);
	dp2[n] = arr[n];
	for (int i = n - 1; i > 0; i--)
		dp2[i] = max(dp2[i + 1] + arr[i], arr[i]);
	
	int ans = dp1[1];
	for (int i = 2; i <= n; i++) 
		ans = max({ans, dp1[i - 1] + dp2[i + 1],dp1[i]});
	cout << ans << '\n';

}