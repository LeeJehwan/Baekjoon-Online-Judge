#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			cout << " ";
		}
		for (int j = 1; j <= n; j++)
			cout << "* ";
		cout << endl;
	}
}