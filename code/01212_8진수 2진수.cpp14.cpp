#include <iostream>
using namespace std;

char arr[340000];
char *str[] = { "000","001","010","011","100","101","110","111" };
char *str2[] = { "0","1","10","11","100","101","110","111" };

void solve(int len) {
	int num;
	for (int i = 0; i < len; i++) {
		num = arr[i]-48;
		if (i == 0) {
			cout << str2[num];
			continue;
		}
		cout << str[num];
	}
	cout << endl;
}

int main() {
	cin >> arr;
	int len=0;
	for (int i = 0;; i++) {
		if (arr[i] == '\0')
			break;
		len++;
	}
	solve(len);
}