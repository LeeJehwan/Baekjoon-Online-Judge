#include <iostream>
#include <algorithm>
using namespace std;

int find_eight(int x) {
	int count = 0;
	while (x) {
		if (x % 10 == 8)
			count++;
		x /= 10;
	}
	return count;
}

int find_eight2(int x, int y) {
	int count = 0;
	while (x) {
		if (x % 10 == y % 10)
			count++;
		else
			count = 0;
		x /= 10;
		y /= 10;
	}
	return count;
}


int max_eight(int x) {
	int count = 0;
	while (x) {
		count++;
		x /= 10;
	}
	return count;
}


int main() {
	int L, R;
	cin >> L >> R;
	int Lmax = max_eight(L);
	int Rmax = max_eight(R);
	int min_eight = find_eight(L);

	if (Rmax - Lmax == 0) {
		int temp = Rmax - find_eight2(L, R);
		for (int i = 0; i < temp; i++)
			L /= 10;
		min_eight = find_eight(L);
	}
	else
		min_eight = 0;

	cout << min_eight << endl;

}