#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char arr[50][51];
	char ans[50];

	for (int i = 0; i < 50; i++)
		ans[i] = '?';

	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
		cin >> arr[i];
	int len = strlen(arr[0]);

	for (int j = 0; j < len; j++) {
		for (int i = 0; i < num; i++) {
			if (arr[0][j] != arr[i][j])
				break;
			if ((i == num - 1) && (arr[0][j] == arr[i][j]))
				ans[j] = arr[0][j];
		}
	}
	ans[len] = '\0';
	cout << ans << endl;

	return 0;
}