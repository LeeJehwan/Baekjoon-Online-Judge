#include <iostream>
using namespace std;

int main() {
	int m1, n1;
	cin >> m1 >> n1;
	int arr1[100][100];
	for (int i = 0; i < m1; i++)
		for (int j = 0; j < n1; j++)
			cin >> arr1[i][j];
	int m2, n2;
	cin >> m2 >> n2;
	int arr2[100][100];
	for (int i = 0; i < m2; i++)
		for (int j = 0; j < n2; j++)
			cin >> arr2[i][j];

	int arr3[100][100] = { 0 };
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n2; j++) {
			for (int k = 0; k < n1; k++) {
				arr3[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n2; j++)
			cout<< arr3[i][j]<<" ";
		cout << endl;
	}
}