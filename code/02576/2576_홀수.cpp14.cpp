#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int num;
	vector<int>v;
	
	for (int i = 0; i < 7; i++) {
		cin >> num;
		if (num % 2 == 1)
			v.push_back(num);
	}
	int len = v.size();
	if (len == 0) {
		cout << -1<<endl;
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum += v[i];
	sort(v.begin(), v.end());
	cout << sum << endl;
	cout << v[0] << endl;

}

