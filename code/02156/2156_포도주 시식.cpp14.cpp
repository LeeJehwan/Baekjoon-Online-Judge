#include <iostream>
using namespace std;

int dp[10001][3];

int max(int n1, int n2,int n3) {
	int max = n1;
	if (max < n2)
		max = n2;
	if (max < n3)
		max = n3;
	return max;
}

int wine(int arr[],int num) {
	dp[1][1] = arr[1];
	dp[2][0] = arr[1];
	dp[2][1] = arr[2];
	dp[2][2] = arr[1]+arr[2];

	for (int i = 3; i <= num; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + arr[i];
		dp[i][2] = dp[i - 1][1] + arr[i];
	}
	return max(dp[num][0], dp[num][1],dp[num][2]);
}

int main() {
	int num;
	cin >> num;
	int arr[10001];
	arr[0] = 0;
	for (int i = 1; i <= num; i++)
		cin >> arr[i];
	cout<<wine(arr, num)<<endl;
}