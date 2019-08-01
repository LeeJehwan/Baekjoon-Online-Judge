#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define endl '\n'
long long fact[21];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	fact[1] = 1;
	for (int i = 2; i <= 20; i++) {
		fact[i] = fact[i - 1] * i;
	}

	set<int> s;
	for (int i = 1; i <= n; i++)
		s.insert(i);
	int mode;
	cin >> mode;
	if (mode == 1) {
		long long k;
		cin >> k;

		while (n != 0) {
			if (k == 1) {
				for (auto x : s) {
					cout << x << ' ';
				}
				break;
			}
			else if (fact[n - 1] < k) {
				auto it = s.begin();
				while (1) {
					if (fact[n - 1] >= k) {
						cout << *it << ' ';
						n--;
						s.erase(*it);
						break;
					}
					++it;
					k -= fact[n - 1];
				}
			}
			else {
				cout << *s.begin() << ' ';
				s.erase(s.begin(), ++s.begin());
				n--;
			}
		}
	}
	else if (mode == 2) {
		long long ans = 1;
		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;

			auto it = s.begin();

			int cnt = 0;
			while (1) {
				if (tmp > *it) {
					cnt++;
					++it;
					continue;
				}

				ans += cnt * fact[n - i];
				s.erase(tmp);
				break;
			}
		}
		cout << ans << endl;
	}

}