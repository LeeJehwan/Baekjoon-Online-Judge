#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
#define endl '\n'


bool chk[10001];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j < b; j++) {
			chk[j] = true;
		}
	}
	int cnt = 0;
	for (bool x : chk) {
		if (x)
			cnt++;
	}
	cout << cnt << endl;
}