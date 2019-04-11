#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	int x1, x2, x3, x4;
	cin >> x1 >> x2 >> x3 >> x4;
	int sum = (x1 + x2 + x3 + x4);
	cout << sum / 60 << endl;
	cout << sum % 60 << endl;
}