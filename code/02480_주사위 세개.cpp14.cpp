#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int price = 0;

	if (a == b && b == c) {
		price = 10000 + a * 1000;
	}
	else if (a == b || a ==c ) {
		price = 1000 + a * 100;
	}
	else if (b == c) {
		price = 1000 + b * 100;
	}
	else {
		price = max({ a,b,c }) * 100;
	}
	cout << price << endl;
}