#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int max, mid, min;
	max = a;
	min = a;

	if (max < b) {
		min = max;
		max = b;
	}else
		min = b;

	if (max < c)
		max = c;

	if (min > c)
		min = c;

	mid = a + b + c - min - max;
	cout << mid << endl;


	return 0;
		
}
