#include <iostream>
using namespace std;


int main() {
	int arr1[3];
	int arr2[2];
	int arr3[6];
	int k = 0;
	for (int i = 0; i < 3; i++)
		cin >> arr1[i];
	for (int i = 0; i < 2; i++)
		cin >> arr2[i];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			arr3[k++] = arr1[i] + arr2[j]-50;
	int min = arr3[0];
	for (int i = 0; i < 6; i++)
		if (min > arr3[i])
			min = arr3[i];
	cout << min << endl;
}