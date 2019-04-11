#include <iostream>
using namespace std;

void run() {
	int m, n, x, y;
	cin >> m >> n >> x >> y;
	x -= 1;
	y -= 1;
	long long count = 1;
	int i = 0;
	while (1) {
		if(count > (m)*(n)) {
			cout << -1 << endl;
			return;
		}
		
		count = (i++)*m + x;
		if ((count % n) == y)
			break;

	}
	cout << count + 1 << '\n';
}



int main() {
	int t;
	cin >> t;
	while (t--) {
		run();
	}
}