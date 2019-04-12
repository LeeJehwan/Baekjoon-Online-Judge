#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i <= 6; i++) {
		if (n&(1 << i))
			ans++;
	}
	cout << ans << endl;
}