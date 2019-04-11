#include <iostream>
using namespace std;

int main() {
	int add, sub;
	cin >> add >> sub;

	int sum = add + sub;
	if (sum % 2 != 0 || (add == 0 && sub!=0) || (sub>add)) {
		cout << -1<<endl;
		return 0;
	}
	int a=sum / 2;
	int b = add - a;

	int max, min;
	if (a > b) {
		max = a;
		min = b;
	}
	else {
		max = b;
		min = a;
	}
	cout << max << " " << min << endl;
	return 0;
}