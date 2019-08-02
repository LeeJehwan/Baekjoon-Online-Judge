#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
	int sum = 0;
	int ans = 0;
	for (int i = 1; i <= 10; i++) {
		int a, b;
		cin >> a >> b;
		sum = sum - a + b;
		ans = max(ans, sum);
	}
	cout << ans << endl;
}
