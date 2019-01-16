#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int card[500001];
void find(int n, int a) {
	int position = -1;
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (card[mid] == a) {
			position = mid;
			break;
		}
		else if (card[mid] < a)
			left = mid + 1;
		else
			right = mid - 1;
	}

	if (position == -1)
		cout << 0 << " ";
	else
		cout << 1 << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	sort(card, card + n);

	int m;
	cin >> m;

	while (m--) {
		int t;
		cin >> t;
		find(n, t);
	}
}