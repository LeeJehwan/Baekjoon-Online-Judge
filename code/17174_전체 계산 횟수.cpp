#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int ans = n;
	
	while (1) {
		int t = n / m;
		if (!t)
			break;

		ans += t;
		n = t;
	}

	cout << ans << endl;
}
