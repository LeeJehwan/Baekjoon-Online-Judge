#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v(3);
	cin >> v[0] >> v[1] >> v[2];
	sort(v.begin(), v.end());

	string s;
	cin >> s;
	for (auto x : s) {
		cout << v[x - 'A'] << " ";
	}
	cout << endl;
}