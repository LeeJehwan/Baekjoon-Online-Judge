#include <iostream>
using namespace std;

int main() {
	int arr[9];
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sum -= 100;
	int a, b;
	for(int i=0;i<9;i++)
		for(int j=i;j<9;j++)
			if (i != j && arr[i] + arr[j] == sum) {
				a = i;
				b = j;
				break;
			}

	for (int i = 0; i < 9; i++) {
		if (i == a || i == b)
			continue;
		cout << arr[i] << endl;
	}
}