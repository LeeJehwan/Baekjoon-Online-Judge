#include <iostream>
using namespace std;


int main() {
	int num;
	cin >> num;
	int sum = 0;

	for (int i = 0; i < num; i++) {
		sum += i + 1;
	}
	cout << sum << endl;
}