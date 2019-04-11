#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char *str[] = { "advertise","do not advertise","does not matter" };

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int r, e, c;
		cin >> r >> e >> c;
		int sum = (e - c) - r;
		if (sum > 0)
			cout << str[0] << endl;
		else if (sum == 0)
			cout << str[2] << endl;
		else
			cout << str[1] << endl;
	}

}

