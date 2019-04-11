#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, s;
int cnt = 0;
void go(vector<int> &v, int sum, int index, int s) {
	int len = n;
	if (len == index && sum == s) {
		cnt++;
		return;
	}
	if (len == index)
		return;

	go(v, sum + v[index], index + 1, s);
	go(v, sum, index + 1, s);
}



int main() {
	cin >> n >> s;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	go(v, 0, 0, s);
	if (s == 0)
		cnt -= 1;
	cout << cnt << '\n';
}