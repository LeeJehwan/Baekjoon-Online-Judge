#include <iostream>
#include <string>
using namespace std;

int arr[100];
int main() {
	int money = 5000;
	string str;
	getline(cin, str);

	int cnt = 0;
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			arr[cnt++] = str[i] - '0';
		}
	}
	for (int i = 0; i < cnt; i++) {
		if (arr[i] == 1) money -= 500;
		else if (arr[i] == 2) money -= 800;
		else if (arr[i] == 3) money -= 1000;
	}
	cout << money << endl;
}