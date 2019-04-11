#include <iostream>
using namespace std;

int goon[5000];

int main() {
	int sum = 1;
	int x;
	for (int i = 0; i < 5000; i++){
		goon[i] = sum;
		sum += (i + 1);
		if (goon[i] > 10000000)
			break;
	}
	
	cin >> x;
	int y;
	for (y = 0; y < 5000; y++) {
		if (x < goon[y])
			break;
	}
	int z = x - goon[y - 1];

	if (y % 2 == 0) {
		cout << 1 + z << "/" << y - z << endl;
	}
	else
		cout << y - z << "/" << 1 + z << endl;

}