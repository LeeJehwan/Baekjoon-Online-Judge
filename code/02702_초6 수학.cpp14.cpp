#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int aaa = 1;
		int bbb = 1;
		for (int i = 2; i <= min(a, b); i++) {
			if (a%i == 0 && b%i == 0) {
				aaa *= i;
				bbb *= i;
				a /= i;
				b /= i;
				i = 1;
			}
		}
		aaa = aaa*a*b;
		cout << aaa << " " << bbb << endl;

	}
}
