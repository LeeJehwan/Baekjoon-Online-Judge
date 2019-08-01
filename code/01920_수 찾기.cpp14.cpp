#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector <int>v;

void search(int start,int end, int m) {
	int mid = (start + end) / 2;
	if (m == v[mid]) {
		cout << 1 << '\n';
		return;
	}
	if (start > end) {
		cout << 0 << '\n';
		return;
	}
	if (m > v[mid])
		search(mid + 1, end, m);
	if (m < v[mid])
		search(start, mid - 1, m);
}

int main() {
	int n, m;
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		search(0, n - 1, temp);
	}

}