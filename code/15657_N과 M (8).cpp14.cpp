// n 개중에 m개를 비내림차순 고른 수열
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
int n, m;
int arr[10];
vector<int> v;
void dfs(int a) {
	if (v.size() == m) {
		for (auto x : v)
			cout << x << " ";
		cout << endl;
		return;
	}

	for (int i = a; i < n; i++) {
		v.push_back(arr[i]);
		dfs(i);
		v.pop_back();
	}

}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dfs(0);
}