#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	int n;
	cin >> n;
	int k = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j+=k) {
			cout << '*';
		}
		cout << endl;
	}
	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << '*';
		}
		cout << endl;
	}

}