#include <iostream>
using namespace std;

int main() {
	long long sum;
	cin >> sum;

	int i = 1;
	long long num = 0;
	while (num <=sum) {
		num += i++;
	}
	cout << i - 2 << endl;
	
}