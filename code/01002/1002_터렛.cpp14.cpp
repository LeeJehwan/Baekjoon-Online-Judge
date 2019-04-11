#include <iostream>
#include <cmath>
using namespace std;


void turret() {
	int x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	int radius_sum = (r1 + r2)*(r1 + r2);
	int radius_sub = (r1 - r2)*(r1 - r2);

	int distance = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);

	if (distance == 0 && r1 == r2) {
		cout << -1 << endl;
		return;
	}
	else if(distance == 0 && r1 != r2) {
		cout << 0 << endl;
		return;
	}

	if (distance > r1*r1 && distance > r2*r2) {
		if (distance > radius_sum)
			cout << 0 << endl;
		else if (distance == radius_sum)
			cout << 1 << endl;
		else if (distance < radius_sum)
			cout << 2 << endl;
		return;
	}

		if (distance > radius_sub)
			cout << 2 << endl;
		else if (distance == radius_sub)
			cout << 1 << endl;
		else if (distance < radius_sub)
			cout << 0 << endl;

}


int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		turret();
	}
}