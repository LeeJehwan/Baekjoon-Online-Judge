#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	vector<pair<int, int>> v;
	for (int i = 0; i < 8; i++) {
		int temp;
		cin >> temp;
		v.push_back(make_pair(temp, i + 1));
	}
	sort(v.begin(), v.end());

	int sum = 0;
	int arr[5];
	for (int i = 3; i < 8; i++) {
		sum += v[i].first;
		arr[i-3] = v[i].second;
	}
	sort(arr, arr + 5);
	cout << sum << endl;
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << endl;

}