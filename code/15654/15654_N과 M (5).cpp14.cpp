// n 개중에 m개를 고른 수열 순서 고려해서
// nPm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
int n, m;
int arr[10];
bool chk[10001];
vector<int> v;
void dfs() {
	if (v.size() == m) {
		for (auto x : v)
			cout << x << " ";
		cout << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!chk[arr[i]]) {
			v.push_back(arr[i]);
			chk[arr[i]] = true;
			dfs();
			v.pop_back();
			chk[arr[i]] = false;
		}
	}

}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dfs();
}