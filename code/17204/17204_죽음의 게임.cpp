#include <iostream>
using namespace std;
#define endl '\n'

int point[155];
int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> point[i];

	int p = point[0];
	int ans = 1;
	while(1){
		if (p == k) {
			cout << ans << endl;
			return 0;
		}
		if (ans >= n * 2)
			break;

		p = point[p];
		ans++;
	}

	cout << -1 << endl;

}