#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	int arr1[10];
	int arr2[10];
	for (int i = 0; i < 10; i++)
		cin >> arr1[i];
	for (int i = 0; i < 10; i++)
		cin >> arr2[i];
	sort(arr1, arr1 + 10);
	sort(arr2, arr2 + 10);
	int sum1 = 0, sum2 = 0;
	sum1 = arr1[7] + arr1[8] + arr1[9];
	sum2 = arr2[7] + arr2[8] + arr2[9];
	cout << sum1 << " " << sum2 << endl;
}