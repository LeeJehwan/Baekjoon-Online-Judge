#include <iostream>
using namespace std;


int main() {
	int num;
	cin >> num;

	int arr1[200][3];

	for (int i = 0; i < num; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr1[i][j];

	int arr2[200][3];
	for (int i = 0; i < num; i++)
		for (int j = 0; j < 3; j++)
			arr2[i][j] = arr1[i][j];

	for (int c = 0; c < 3; c++) {
		for (int i = 0; i < num; i++) {
			for (int j = i+1; j < num; j++) {
				if (arr1[i][c] == arr1[j][c]) {
					arr2[i][c] = 0;
					arr2[j][c] = 0;
				}
			}
		}
	}
	for (int i = 0; i < num; i++) 
		for (int j = 1; j < 3; j++)
			arr2[i][0] += arr2[i][j];

	for (int i = 0; i < num; i++)
		cout << arr2[i][0] << endl;
	
}