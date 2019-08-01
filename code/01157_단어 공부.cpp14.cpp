#include <iostream>
using namespace std;

int main() {
	int ch;
	int arr[26] = { 0 };
	int num;

	ch = getchar();
	if (ch <= 90 )
		ch = ch + 32;
	num = ch - 97;
	arr[num]++;

	while ((ch = getchar()) != '\n') {
		if (ch <= 90)
			ch = ch+32;
		num = ch - 97;
		arr[num]++;
	}

	int max = 0, max_i = 0, count = 0;

	for (int i = 0; i<26; i++)
		if (max < arr[i]) {
			max = arr[i];
			max_i = i;
		}

	for (int i = 0; i < 26; i++)
		if (arr[max_i] == arr[i])
			count++;
	
	if (count > 1)
		printf("%c\n", '?');
	else {
		printf("%c\n", 65 + max_i);
	}
	return 0;
}