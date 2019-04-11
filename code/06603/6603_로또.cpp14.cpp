#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> lotto;
void go(vector<int> &v, int index, int count) {
	if (count == 6) {
		for (auto x : lotto)
			cout << x << " ";
		cout << '\n';
		return;
	}
	int len = v.size();
	if (len == index)
		return;

	lotto.push_back(v[index]);
	go(v, index + 1, count + 1);
	lotto.pop_back();
	go(v, index + 1, count);
}


int main() {
	while (1) {
		int k;
		cin >> k;
		if (k == 0)
			break;
		vector<int> v(k);
		for (int i = 0; i < k; i++)
			cin >> v[i];
		go(v, 0, 0);

		cout << endl;
	}
}