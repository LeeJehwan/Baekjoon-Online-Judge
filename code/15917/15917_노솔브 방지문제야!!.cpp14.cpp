#include <iostream>
using namespace std;

void solve(int n) {
	if ((n&-n) == n)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		solve(n);
	}
}