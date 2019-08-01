#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a = sqrt(n);
	int sum = n;
	for (int i = 2; i <= a; i++) {
		sum += ((n - i*i) / i + 1);
	}
	cout << sum << endl;
}