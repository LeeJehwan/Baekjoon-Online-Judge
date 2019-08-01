#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int	arr[1005];
int main() {
	int n, L;
	cin >> n >> L;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (L >= arr[i])
			L += 1;
		else {
			break;
		}
	}

	cout << L << endl;
}