#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findLen(int num) {
	int count = 0;
	while (1) {
		if (num == 0)
			break;
		num = num / 10;
		count++;
	}
	return count;
}

int main() {
	long long arr[4];
	for (int i = 0; i < 4; i++)
		cin >> arr[i];
	int len1 = findLen(arr[1]);
	int len2 = findLen(arr[3]);
	for (int i = 0; i < len1; i++)
		arr[0] = arr[0] * 10;
	for (int i = 0; i < len2; i++)
		arr[2] *= 10;
	long long sum = 0;
	for (int i = 0; i < 4; i++)
		sum += arr[i];
	cout << sum << endl;
}

