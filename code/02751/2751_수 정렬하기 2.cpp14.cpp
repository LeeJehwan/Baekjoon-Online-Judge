#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000050];

int main() {
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
		cin >> arr[i];
	sort(arr, arr + num);
	for (int i = 0; i < num; i++)
		cout << arr[i] << '\n';
}