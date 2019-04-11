#include <iostream>
using namespace std;
#define endl '\n'

int gcd(int a, int b) {
	if (b == 0) return a;
	else {
		return gcd(b, a%b);
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	cout << m - gcd(n, m) << endl;
}