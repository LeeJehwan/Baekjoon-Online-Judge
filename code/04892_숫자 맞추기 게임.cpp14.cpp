#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define endl '\n'

int main() {
	
	for (int z = 1; ; z++) {
		int n0, n1, n2, n3, n4, ans;
		cin >> n0;
		if (n0 == 0)
			break;
		
		n1 = n0 * 3;
		if (n1 % 2 == 0)
			n2 = n1 / 2;
		else
			n2 = (n1 + 1) / 2;

		n3 = n2 * 3;
		n4 = n3 / 9;

		cout << z << ". ";
		if (n1 % 2 == 0)
			cout << "even ";
		else
			cout << "odd ";

		cout << n4 << endl;
	}
}