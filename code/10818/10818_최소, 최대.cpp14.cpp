#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num;
	cin >> num;
	int a;
	vector<int>v;
	for (int i = 0; i < num; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	cout << v[0] << " " << v[v.size() - 1] << endl;
}

