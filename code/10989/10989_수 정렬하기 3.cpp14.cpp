#include <iostream>
#include <cstdio>
using namespace std;

int dp[10005];

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int temp;
		scanf("%d", &temp);
		dp[temp]++;
	}
	
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < dp[i]; j++)
			printf("%d\n", i);
	}
}