#include <iostream>
#include <string>
using namespace std;

int main() {
	int L, R;
	cin >> L >> R;

	int ans = 0;
	int idx = 2;
	while (1) {
		int tmp = (int)((double)(L * R) / 100);
		if (tmp <= 5) break;
		ans += tmp * idx;
		idx *= 2;
			   
		L = tmp;
	}
	cout << ans << endl;
}