#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char arr[9][9];
	memset(arr, 0, sizeof(arr));
	int count = 0;
	for (int i = 0; i < 8; i++)
		cin >> arr[i];

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if ((i + j) % 2 == 0 && arr[i][j] == 'F')
				count++;

	cout << count << endl;


}