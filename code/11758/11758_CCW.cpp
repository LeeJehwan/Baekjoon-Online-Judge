#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define endl '\n'

int main() {
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	int ccw = (x1*y2 + x2 * y3 + x3 * y1) - (x2*y1 + x3 * y2 + x1 * y3);
	if (ccw < 0)
		cout << -1 << endl;
	else if (ccw == 0)
		cout << 0 << endl;
	else
		cout << 1 << endl;

}