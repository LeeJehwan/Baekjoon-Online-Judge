#include <iostream>
using namespace std;

long long fibo2(int n) {
	static long long memo[100];
	if (n == 1 || n == 2)
		return memo[n] = 1;
	if (memo[n] > 0)
		return memo[n];
	return memo[n] = fibo2(n - 1) + fibo2(n - 2);
}

int main() {
	int num;
	cin >> num;

	long long fff=fibo2(num);
	cout << fff << endl;
	return 0;

}