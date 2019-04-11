#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int arr[2];
int main() {
	string str;
	cin >> str;

	if (str.size() == 1) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1; i < str.size(); i++) {
		if (str[i] != str[i - 1]) {
			arr[int(str[i - 1] - '0')] ++;
		}
	}
	arr[int(str[str.size() - 1] - '0')]++;
	
	cout << min(arr[0], arr[1]) << endl;
}