#include <iostream>

using namespace std;

int main() {
	char str[50];
	cin >> str;
	int sum = 10;
	int i = 0;
	while (str[i] != 0) {
		i++;
	}
	int len = i;
	for (int i = 1; i < len; i++) {
		if (str[i] != str[i - 1])
			sum += 10;
		else
			sum += 5;
	}
	cout << sum << endl;
	
	
	return 0;
}