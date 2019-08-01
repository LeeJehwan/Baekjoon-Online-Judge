#include <iostream>
using namespace std;

int arr[501][501];
int dp[501][501];

int max(int num1, int num2) {
	if (num1 > num2)
		return num1;
	return num2;
}

int numTri(int num) {

		for (int i = 1; i <= num; i++)
			dp[num][i] = arr[num][i];
	

	for (int i = num; i > 1; i--) {
		for (int j = 1; j <i; j++) {
			dp[i - 1][j] = max(dp[i][j], dp[i][j + 1]) + arr[i - 1][j];
		}
	}
	return dp[1][1];
}




int main() {
	int num;
	cin >> num;
	

	for (int i = 1; i <= num; i++) 
		for (int j = 1; j <= i; j++)
			cin >> arr[i][j];

	cout << numTri(num) << endl;

}