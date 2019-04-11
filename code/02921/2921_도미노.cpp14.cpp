#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	int n;
	cin >> n;

	long long ans = (n*(n + 1)) / 2;
	ans *= (n + 2);
	cout << ans << endl;
}