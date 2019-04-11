#include <iostream>
using namespace std;

int main() {
	int e, s, m;
	cin >> e >> s >> m;
	int count = 1;
	
	int a = 1, b = 1, c = 1;
	while (1) {
		if (a == e && b == s && c == m)
			break;
		a++;
		b++;
		c++;
		count++;

		if (a == 16)
			a = 1;
		if (b == 29)
			b = 1;
		if (c == 20)
			c = 1;
	}

	cout << count << endl;;
}