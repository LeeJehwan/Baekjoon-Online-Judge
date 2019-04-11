#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define endl '\n'

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		bool arr[91];
		memset(arr, 0, sizeof(arr));

		string s;
		cin >> s;

		for (auto x : s) {
			arr[(int)x] = true;
		}
		int sum = 0;
		for (int i = 'A'; i <= 'Z'; i++)
			if (arr[i] == false)
				sum += i;
		cout << sum << endl;

	}
}