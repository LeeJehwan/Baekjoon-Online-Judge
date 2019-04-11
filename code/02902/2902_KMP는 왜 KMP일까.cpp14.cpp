#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
	string ans;
	string in;
	cin >> in;

	int len = in.size();
	ans += in[0];
	for (int i = 1; i < len; i++) {
		if (in[i] == '-')
			ans += in[i + 1];
	}
	cout << ans << endl;
}