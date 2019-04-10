#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v;

	for (int i = 1; i <= n; i++)
		v.push_back(i);

	int tmp = 0;
	cout << '<';
	for (int i = 0; i < n; i++) {
		tmp = (tmp + m - 1) % v.size();
		cout << v[tmp];
		if (v.size() == 1)
			break;
		cout << ", ";

		v.erase(v.begin() + tmp);
	}
	cout << '>' << endl;
}