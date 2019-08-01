#include <iostream>
using namespace std;


int arr[1000001];
int tmp[1000001];
long long ans = 0;
// [start, mid) [mid, end)
void merge(int start, int mid, int end) {
	int p1 = start;
	int p2 = mid;
	int idx = 0;
	while (p1 < mid && p2 < end) {
		if (arr[p1] < arr[p2]) {
			tmp[idx++] = arr[p1++];
		}
		else if (arr[p1] > arr[p2]) {
			tmp[idx++] = arr[p2++];
			ans += mid - p1;
		}
		else {
			tmp[idx++] = arr[p1++];
		}
	}

	while (p1 < mid) {
		tmp[idx++] = arr[p1++];
	}
	while (p2 < end) {
		tmp[idx++] = arr[p2++];
	}

	for (int i = 0; i < end - start; i++) {
		arr[start + i] = tmp[i];
	}
}

void merge_sort(int start, int end) {
	int mid = (start + end) / 2;
	if (start < mid) {
		merge_sort(start, mid);
		merge_sort(mid , end);
		merge(start, mid, end);
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	merge_sort(0, n);
	cout << ans << endl;
}