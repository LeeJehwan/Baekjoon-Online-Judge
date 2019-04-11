#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	int num;
	cin >> num;
	int arr[3];
	for (int i = 0; i < num; i++)
		cin >> arr[i];

	int m = arr[0];
	for (int i = 0; i < num; i++)
		m = min(arr[i], m);
	
	for (int i = 1; i <= m; i++) {
		if (arr[0] % i == 0 && arr[1] % i == 0 && arr[num - 1] % i == 0)
			cout << i << '\n';
	}
}

