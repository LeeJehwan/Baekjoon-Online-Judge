#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int main() {
	int cnt = 1;
	while (1) {
		string ans;
		int r;
		cin >> r;
		if (r == 0)
			break;
		int a, b;
		cin >> a >> b;

		int d = a * a + b * b;
		int k = (2 * r)*(2 * r);


		if (k >= d)
			ans = "fits on the table.";
		else
			ans = "does not fit on the table.";

		
		cout << "Pizza " << cnt++ << " " << ans << endl;

	}

}