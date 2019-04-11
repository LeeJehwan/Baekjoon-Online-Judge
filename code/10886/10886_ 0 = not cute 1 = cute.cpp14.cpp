#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	char *str1[] = { "Junhee is cute!","Junhee is not cute!" };
	int arr[105];

	int num;
	int sum = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	if (sum > num/2)
		cout << str1[0]<<endl;
	else
		cout << str1[1]<<endl;


}

