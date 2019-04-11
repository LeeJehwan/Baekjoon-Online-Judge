#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int maxAns = -1000000001;
int minAns = 1000000001;
void go(vector<int> &a, int index, int cur, int plus, int minus, int mul, int div) {
	int len = a.size();
	if (len == index) {
		if (cur > maxAns)
			maxAns = cur;
		if (cur < minAns)
			minAns = cur;
		return;
	}

	if (plus != 0)
		go(a, index + 1, cur + a[index], plus - 1, minus, mul, div);
	if (minus != 0)
		go(a, index + 1, cur - a[index], plus , minus-1, mul, div);
	if (mul != 0)
		go(a, index + 1, cur * a[index], plus , minus, mul-1, div);
	if (div != 0)
		go(a, index + 1, cur / a[index], plus , minus, mul, div-1);


}

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int arr[4];
	for (int i = 0; i < 4; i++)
		cin >> arr[i];

	go(v, 1, v[0], arr[0], arr[1], arr[2], arr[3]);
	cout << maxAns << '\n';
	cout << minAns << '\n';
}