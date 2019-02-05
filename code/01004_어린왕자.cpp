#include <iostream>
using namespace std;

void solve() {
	int sx, sy, dx, dy;
	cin >> sx >> sy >> dx >> dy;
	int n;
	cin >> n;

	int count_a = 0, count_b = 0;
	bool A = false;
	bool B = false;
	for (int i = 0; i < n; i++) {
		A = B = false;
		int cx, cy, r;
		cin >> cx >> cy >> r;
		int tA = (sx - cx)*(sx - cx) + (sy - cy)*(sy - cy);
		if (tA < r*r)
			A = true;
		int tB = (dx - cx)*(dx - cx) + (dy - cy)*(dy - cy);
		if (tB < r*r)
			B = true;
		if (A && B)
			continue;
		if (A == true)
			count_a++;
		if (B == true)
			count_b++;
	}
	cout << count_a + count_b << endl;

}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}