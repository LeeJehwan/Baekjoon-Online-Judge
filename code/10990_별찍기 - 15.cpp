#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n - 1; j++) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < 2 * (i-1) + 1; j++) {
			cout << " ";
		}
		if(i != 0)
			cout << '*';
		cout<< endl;
	}
}