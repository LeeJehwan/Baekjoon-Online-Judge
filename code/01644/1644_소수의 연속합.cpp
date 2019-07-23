#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int prime[4000001];
bool count_p[4000001];
int cnt = 0;
void eratos() {
	for (int i = 2; i <= 4000000; i++) {
		if (count_p[i] == false)
			prime[cnt++] = i;
		for (int j = i * 2; j <= 4000000; j += i)
			count_p[j] = true;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	eratos();

	int n;
	cin >> n;

	int ans = 0;
	int i = 0, j = 0;
	long long sum = 0;
	while (1) {
		if (j == i + 1 && prime[i] > n) break;

		if (i == j) {
			sum += prime[j++];
		}
		else if (sum > n) {
			sum -= prime[i++];
		}
		else if (sum == n) {
			ans++;
			sum -= prime[i++];
		}
		else if (sum < n) {
			sum += prime[j++];
		}
	}

	cout << ans << endl;
}