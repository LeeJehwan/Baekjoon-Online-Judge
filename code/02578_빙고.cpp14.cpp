#include <iostream>
using namespace std;

int bingo[5][5];
int temp[5][5];
int arr[5][5];

int isBingo() {
	int count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (temp[i][j] == 0)
				break;
			if (j==4 && temp[i][j] == 1)
				count++;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (temp[j][i] == 0)
				break;
			if (j==4 && temp[j][i] == 1)
				count++;
		}
	}

	for (int i = 0; i < 5; i++) {
		if (temp[i][i] == 0)
			break;
		if (i==4 && temp[i][i] == 1)
			count++;
	}

	for (int i = 0; i < 5; i++) {
		if (temp[i][4-i] == 0)
			break;
		if (i==4 && temp[i][4-i] == 1)
			count++;
	}

	return count;
}

int search(int num) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (num == bingo[i][j]) {
				temp[i][j]++;
				return isBingo();
			}
		}
	}
}


int main() {
	int count = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> bingo[i][j];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			count = search(arr[i][j]);
			if (count >= 3) {
				cout << 5 * i + j + 1 << endl;
				return 0;
			}
		
		}


}