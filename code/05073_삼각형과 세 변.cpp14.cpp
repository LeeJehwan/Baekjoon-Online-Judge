#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
	int arr[3];
	while (1) {
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr + 3);

		if ((arr[0] == arr[1]) && (arr[1] == arr[2])) {
			if (arr[0] == 0) {
				break;
			}
			else {
				cout << "Equilateral" << endl;
			}
		}

		else if (arr[0] + arr[1] <= arr[2]) {
			cout << "Invalid" << endl;
		}
		else if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2]) {
			cout << "Isosceles" << endl;
		}
		else
			cout << "Scalene" << endl;
	}
}