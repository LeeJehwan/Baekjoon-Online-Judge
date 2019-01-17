#include <iostream>
using namespace std;
#define endl '\n'
#define MAX_BIT (10000000)/(8)

char bit[MAX_BIT];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		int t1 = bit[t / 8];
		bit[t / 8] |= (1 << (t % 8));
		int t2 = bit[t / 8];
		if (t1 == t2) {
			cout << t << endl;
			return 0 ;
		}
	}

}
