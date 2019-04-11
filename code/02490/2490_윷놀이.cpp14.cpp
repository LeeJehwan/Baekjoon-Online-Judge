#include <iostream>
using namespace std;
int main() {
	for (int i = 0; i < 3; i++) {
		int arr[4];
		int sum = 0;
		for (int j = 0; j < 4; j++)
			cin >> arr[j];
		for (int j = 0; j < 4; j++)
			sum += arr[j];
		char arr2[5] = { 'D','C','B','A','E' };

		cout << arr2[sum] << endl;
	}
}