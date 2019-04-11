#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
using namespace	std;
#define endl '\n'


int main() {
	int n, m;
	cin >> n >> m;

	int arr[101][101];
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int t;
			cin >> t;
			arr[i][j] += t;
		}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}


}