#include <iostream>
#include <cstring>
using namespace std;

int main() {
	bool arr[31];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < 28; i++) {
		int temp;
		cin >> temp;
		arr[temp] = true;
	}
	for (int i = 1; i <= 30; i++) {
		if (!arr[i])
			cout << i << endl;
	}

}