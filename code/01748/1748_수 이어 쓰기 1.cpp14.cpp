#include <iostream>
using namespace std;

long long ans = 0;
int main() {
	int n;
	cin >> n;

	int tmp = n;
	int len = 0;
	while (tmp != 0) {
		tmp /= 10;
		len++;
	}

	//1~9 : 9개
	//10~99 : 90개
	//100~999 : 900개
	long long sum = 9;
	long long mul = 1;
	for (int i = 1; i < len; i++) {
		ans += sum*i;
		sum *= 10;
		mul *= 10;
	}
	//102개 ; 99까지 함
	tmp = n - mul;
	ans += len*(tmp + 1);


	cout << ans << endl;
}