#include <iostream>
using namespace std;

int arr[1001];
bool chk[1001];
int main() {
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
		cin >> arr[i];

	for (int i = 0; i < m; i++) {
		int tmp = arr[i];
		int idx = 1;
		while (1) {
			if (tmp > n)
				break;
			chk[tmp] = true;
			
			tmp = tmp + arr[i];
		}
	}

	long long ans = 0;
	for (int i = 0; i <= 1000; i++) {
		if (chk[i])
			ans += i;
	}
	cout << ans << endl;
}