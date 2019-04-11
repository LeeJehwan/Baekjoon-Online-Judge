#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int num;
	cin >> num;
	int arr[105];
	for (int i = 1; i <= num; i++)
		cin >> arr[i];

	arr[0] = 0;
	int arr2[105];
	arr2[0] = 0;
	for (int i = 1; i <= num; i++) {
		arr2[i] = arr[i] * i - arr[i-1]*(i-1);
		cout << arr2[i] << " ";
	}
	cout << endl;
	
}

