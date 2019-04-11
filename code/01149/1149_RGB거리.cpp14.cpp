#include <iostream>
#include <algorithm>
using namespace std;

int rgb[1002][3];
#define R 0
#define G 1
#define B 2

void solve(int houseNum) {
	for (int i = 2; i <= houseNum; i++) {
		rgb[i][R] = min(rgb[i - 1][G], rgb[i - 1][B]) + rgb[i][R];
		rgb[i][G] = min(rgb[i - 1][R], rgb[i - 1][B]) + rgb[i][G];
		rgb[i][B] = min(rgb[i - 1][R], rgb[i - 1][G]) + rgb[i][B];
	}
	cout << min({ rgb[houseNum][R],rgb[houseNum][G] ,rgb[houseNum][B] }) << endl;
}

int main() {
	int houseNum;
	cin >> houseNum;

	for (int i = 1; i <= houseNum; i++) 
		for (int j = 0; j < 3; j++)
			cin >> rgb[i][j];
	
	solve(houseNum);
}