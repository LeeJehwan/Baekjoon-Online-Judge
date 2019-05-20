#include <iostream>
#include <cmath>
using namespace std;
#define endl '\n'

int note[1005];
int	seg[1005];
int sum[1005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
		cin >> note[i];
	for (int i = 1; i < n; i++)
		seg[i] = abs(note[i] - note[i + 1]);
	for (int i = 1; i < n; i++) 
		sum[i] = sum[i - 1] + seg[i];
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << sum[r - 1] - sum[l - 1] << endl;
	}
}