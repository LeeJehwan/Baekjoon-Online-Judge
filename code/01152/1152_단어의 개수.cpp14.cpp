#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
	char arr[1000001];
	int count = 0;
	char ch;
	int i = 0;
	while (1) {
		ch = getchar();
		if (ch == EOF || ch == '\n')
			break;
		arr[i++] = ch;
	}
	arr[i] = '\0';
	int len = strlen(arr);
	int sw = 0;
	for (int i = 0; i < len; i++) {
		if (arr[i] != ' ')
			sw++;
		if (arr[i] == ' ')
			sw = 0;
		if (sw == 1)
			count++;
	}
	cout << count << endl;

}