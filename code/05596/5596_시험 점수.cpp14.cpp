#include <iostream>
#include <algorithm>

using namespace std;
int main() {	
	int arr1[4];
	int arr2[4];
	for (int i = 0; i < 4; i++)
		cin >> arr1[i];
	for (int i = 0; i < 4; i++)
		cin >> arr2[i];
	int sum1 = 0, sum2 =0;
	for (int i = 0; i < 4; i++) {
		sum1 += arr1[i];
		sum2 += arr2[i];
	}
	cout << max(sum1, sum2) << endl;
}
