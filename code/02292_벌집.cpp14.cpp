#include <iostream>
using namespace std;

int main() {
	int arr[30000];
	arr[0] = 1;
	for (int i = 0; i < 30000; i++) {
		arr[i + 1] = arr[i] + 6 * (i + 1);
		if (arr[i] > 1000000000)
			break;
	}
	int num;
	cin >> num;

	for(int i=0;i<30000;i++)
		if (arr[i] >= num) {
			cout << i + 1 << endl;
			break;
		}
}