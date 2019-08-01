#include <iostream>
#include <string>
using namespace std;
char cube[7][9];


void init() {
	for (int i = 0; i < 9; i++)
		cube[1][i] = 'r';
	for (int i = 0; i < 9; i++)
		cube[2][i] = 'o';
	for (int i = 0; i < 9; i++)
		cube[3][i] = 'w';
	for (int i = 0; i < 9; i++)
		cube[4][i] = 'y';
	for (int i = 0; i < 9; i++)
		cube[5][i] = 'g';
	for (int i = 0; i < 9; i++)
		cube[6][i] = 'b';
}

void rotate2(string str) {
	int k = 0;
	if (str[0] == 'F') k = 1;
	else if (str[0] == 'B') k = 2;
	else if (str[0] == 'U') k = 3;
	else if (str[0] == 'D') k = 4;
	else if (str[0] == 'L') k = 5;
	else if (str[0] == 'R') k = 6;

	int tmp[9];
	if (str[1] == '-') {
		tmp[0] = cube[k][2];
		tmp[1] = cube[k][5];
		tmp[2] = cube[k][8];

		tmp[3] = cube[k][1];
		tmp[4] = cube[k][4];
		tmp[5] = cube[k][7];

		tmp[6] = cube[k][0];
		tmp[7] = cube[k][3];
		tmp[8] = cube[k][6];

	}
	else {
		tmp[0] = cube[k][6];
		tmp[1] = cube[k][3];
		tmp[2] = cube[k][0];

		tmp[3] = cube[k][7];
		tmp[4] = cube[k][4];
		tmp[5] = cube[k][1];

		tmp[6] = cube[k][8];
		tmp[7] = cube[k][5];
		tmp[8] = cube[k][2];
	}

	for (int i = 0; i < 9; i++) {
		cube[k][i] = tmp[i];
	}
}

void rotate(string str) {
	int tmp[3];
	if (str[0] == 'F') {
		if (str[1] == '-') {
			tmp[0] = cube[3][6];
			tmp[1] = cube[3][7];
			tmp[2] = cube[3][8];

			cube[3][6] = cube[6][0];
			cube[3][7] = cube[6][3];
			cube[3][8] = cube[6][6];

			cube[6][0] = cube[4][2];
			cube[6][3] = cube[4][1];
			cube[6][6] = cube[4][0];

			cube[4][2] = cube[5][8];
			cube[4][1] = cube[5][5];
			cube[4][0] = cube[5][2];

			cube[5][8] = tmp[0];
			cube[5][5] = tmp[1];
			cube[5][2] = tmp[2];
		}
		else {
			tmp[0] = cube[3][6];
			tmp[1] = cube[3][7];
			tmp[2] = cube[3][8];

			cube[3][6] = cube[5][8];
			cube[3][7] = cube[5][5];
			cube[3][8] = cube[5][2];

			cube[5][8] = cube[4][2];
			cube[5][5] = cube[4][1];
			cube[5][2] = cube[4][0];

			cube[4][2] = cube[6][0];
			cube[4][1] = cube[6][3];
			cube[4][0] = cube[6][6];

			cube[6][0] = tmp[0];
			cube[6][3] = tmp[1];
			cube[6][6] = tmp[2];
		}
	}
	else if (str[0] == 'B') {
		if (str[1] == '-') {
			tmp[0] = cube[3][0];
			tmp[1] = cube[3][1];
			tmp[2] = cube[3][2];

			cube[3][0] = cube[5][6];
			cube[3][1] = cube[5][3];
			cube[3][2] = cube[5][0];

			cube[5][6] = cube[4][8];
			cube[5][3] = cube[4][7];
			cube[5][0] = cube[4][6];

			cube[4][8] = cube[6][2];
			cube[4][7] = cube[6][5];
			cube[4][6] = cube[6][8];

			cube[6][2] = tmp[0];
			cube[6][5] = tmp[1];
			cube[6][8] = tmp[2];
		}
		else {
			tmp[0] = cube[3][0];
			tmp[1] = cube[3][1];
			tmp[2] = cube[3][2];

			cube[3][0] = cube[6][2];
			cube[3][1] = cube[6][5];
			cube[3][2] = cube[6][8];

			cube[6][2] = cube[4][8];
			cube[6][5] = cube[4][7];
			cube[6][8] = cube[4][6];

			cube[4][8] = cube[5][6];
			cube[4][7] = cube[5][3];
			cube[4][6] = cube[5][0];

			cube[5][6] = tmp[0];
			cube[5][3] = tmp[1];
			cube[5][0] = tmp[2];
		}
	}
	else if (str[0] == 'U') {
		if (str[1] == '-') {
			tmp[0] = cube[1][0];
			tmp[1] = cube[1][1];
			tmp[2] = cube[1][2];

			cube[1][0] = cube[5][0];
			cube[1][1] = cube[5][1];
			cube[1][2] = cube[5][2];

			cube[5][0] = cube[2][0];
			cube[5][1] = cube[2][1];
			cube[5][2] = cube[2][2];

			cube[2][0] = cube[6][0];
			cube[2][1] = cube[6][1];
			cube[2][2] = cube[6][2];

			cube[6][0] = tmp[0];
			cube[6][1] = tmp[1];
			cube[6][2] = tmp[2];
		}
		else {
			tmp[0] = cube[1][0];
			tmp[1] = cube[1][1];
			tmp[2] = cube[1][2];

			cube[1][0] = cube[6][0];
			cube[1][1] = cube[6][1];
			cube[1][2] = cube[6][2];

			cube[6][0] = cube[2][0];
			cube[6][1] = cube[2][1];
			cube[6][2] = cube[2][2];

			cube[2][0] = cube[5][0];
			cube[2][1] = cube[5][1];
			cube[2][2] = cube[5][2];

			cube[5][0] = tmp[0];
			cube[5][1] = tmp[1];
			cube[5][2] = tmp[2];
			
		}
	}
	else if (str[0] == 'D') {
		if (str[1] == '-') {
			tmp[0] = cube[1][6];
			tmp[1] = cube[1][7];
			tmp[2] = cube[1][8];

			cube[1][6] = cube[6][6];
			cube[1][7] = cube[6][7];
			cube[1][8] = cube[6][8];

			cube[6][6] = cube[2][6];
			cube[6][7] = cube[2][7];
			cube[6][8] = cube[2][8];

			cube[2][6] = cube[5][6];
			cube[2][7] = cube[5][7];
			cube[2][8] = cube[5][8];

			cube[5][6] = tmp[0];
			cube[5][7] = tmp[1];
			cube[5][8] = tmp[2];
		}
		else {
			tmp[0] = cube[1][6];
			tmp[1] = cube[1][7];
			tmp[2] = cube[1][8];

			cube[1][6] = cube[5][6];
			cube[1][7] = cube[5][7];
			cube[1][8] = cube[5][8];

			cube[5][6] = cube[2][6];
			cube[5][7] = cube[2][7];
			cube[5][8] = cube[2][8];

			cube[2][6] = cube[6][6];
			cube[2][7] = cube[6][7];
			cube[2][8] = cube[6][8];

			cube[6][6] = tmp[0];
			cube[6][7] = tmp[1];
			cube[6][8] = tmp[2];
		}
	}
	else if (str[0] == 'L') {
		if (str[1] == '-') {
			tmp[0] = cube[1][0];
			tmp[1] = cube[1][3];
			tmp[2] = cube[1][6];

			cube[1][0] = cube[4][0];
			cube[1][3] = cube[4][3];
			cube[1][6] = cube[4][6];

			cube[4][0] = cube[2][8];
			cube[4][3] = cube[2][5];
			cube[4][6] = cube[2][2];

			cube[2][8] = cube[3][0];
			cube[2][5] = cube[3][3];
			cube[2][2] = cube[3][6];

			cube[3][0] = tmp[0];
			cube[3][3] = tmp[1];
			cube[3][6] = tmp[2];
		}
		else {
			tmp[0] = cube[1][0];
			tmp[1] = cube[1][3];
			tmp[2] = cube[1][6];

			cube[1][0] = cube[3][0];
			cube[1][3] = cube[3][3];
			cube[1][6] = cube[3][6];

			cube[3][0] = cube[2][8];
			cube[3][3] = cube[2][5];
			cube[3][6] = cube[2][2];

			cube[2][8] = cube[4][0];
			cube[2][5] = cube[4][3];
			cube[2][2] = cube[4][6];

			cube[4][0] = tmp[0];
			cube[4][3] = tmp[1];
			cube[4][6] = tmp[2];
		}
	}
	else if (str[0] == 'R') {
		if (str[1] == '-') {
			tmp[0] = cube[1][2];
			tmp[1] = cube[1][5];
			tmp[2] = cube[1][8];

			cube[1][2] = cube[3][2];
			cube[1][5] = cube[3][5];
			cube[1][8] = cube[3][8];

			cube[3][2] = cube[2][6];
			cube[3][5] = cube[2][3];
			cube[3][8] = cube[2][0];

			cube[2][6] = cube[4][2];
			cube[2][3] = cube[4][5];
			cube[2][0] = cube[4][8];

			cube[4][2] = tmp[0];
			cube[4][5] = tmp[1];
			cube[4][8] = tmp[2];
		}
		else {
			tmp[0] = cube[1][2];
			tmp[1] = cube[1][5];
			tmp[2] = cube[1][8];

			cube[1][2] = cube[4][2];
			cube[1][5] = cube[4][5];
			cube[1][8] = cube[4][8];

			cube[4][2] = cube[2][6];
			cube[4][5] = cube[2][3];
			cube[4][8] = cube[2][0];

			cube[2][6] = cube[3][2];
			cube[2][3] = cube[3][5];
			cube[2][0] = cube[3][8];

			cube[3][2] = tmp[0];
			cube[3][5] = tmp[1];
			cube[3][8] = tmp[2];
		}
	}

	rotate2(str);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		init();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			rotate(str);
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[3][i * 3 + j];
			}
			cout << endl;
		}	
	}
}