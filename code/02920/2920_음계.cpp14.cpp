#include <iostream>
using namespace std;

int main() {
	int arr[8];
	int count = 0;
	for (int i = 0; i < 8; i++)
		cin >> arr[i];
	for (int i = 0; i < 7; i++) {
		if (arr[i] < arr[i + 1])
			count++;
	}
	if (count == 7) {
		cout << "ascending" << endl;
		return 0;
	}
	else if (count == 0) {
		cout << "descending" << endl;
		return 0;
	}
	else
		cout << "mixed" << endl;
	return 0;

}