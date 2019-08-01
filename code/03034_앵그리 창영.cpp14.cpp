#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n, w, h;
	cin >> n >> w >> h;
	double di = sqrt(w*w + h*h);

	char * str[2] = { "DA","NE" };
	
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (di >= (double)temp)
			cout << str[0] << endl;
		else
			cout << str[1] << endl;
	}

}

