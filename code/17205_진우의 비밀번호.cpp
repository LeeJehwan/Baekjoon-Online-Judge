#include <iostream>
#include <string>
using namespace std;

long long calc(int n1, int n2) {
	long long ans = 0;
	for (int i = 0; i < n2 ; i++) {
		ans = 1 + ans * 26;
	}
	return ans * n1;
}

int main() {
	int n;
	cin >> n;
	string pass;
	cin >> pass;

	long long ans = 0;

	for (int i = 0; i < pass.size(); i++) {
		char ch = pass[i];
		ans += calc((int)(ch - 'a'), n - i);
		ans++;
	}
	cout << ans << endl;
}