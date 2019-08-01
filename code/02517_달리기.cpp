#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> a(500001);
vector<pair<int, int>> tmp(500001);
int ans[500001];
void merge(int start, int mid, int end) {
	int p1 = start;
	int p2 = mid;
	int idx = 0;
	while (p1 < mid && p2 < end) {
		if (a[p1].first < a[p2].first) {
			ans[a[p2].second] -= mid - p1;
			tmp[idx++] = a[p2++];
		}
		else {
			tmp[idx++] = a[p1++];
		}
	}
	while (p1 < mid) {
		tmp[idx++] = a[p1++];
	}
	while (p2 < end) {
		tmp[idx++] = a[p2++];
	}
	for (int i = 0; i < end - start; i++) {
		a[start + i] = tmp[i];
	}
}

void merge_sort(int start, int end) {
	int mid = (start + end) / 2;
	if (start < mid) {
		merge_sort(start, mid);
		merge_sort(mid, end);
		merge(start, mid, end);
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
		ans[i] = i;
	}

	merge_sort(0, n);
	for (int i = 0; i < n; i++)
		cout << ans[i]+1 << endl;
}