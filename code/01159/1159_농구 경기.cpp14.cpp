#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int num;
	cin >> num;
	char str[155][30];
	char ak[27] = { 0, };

	for (int i = 0; i < num; i++) {
		cin >> str[i];
		ak[str[i][0] - 'a']++;
	}
	int	count = 0;
	for (int i = 0; i < 26; i++)
		if (ak[i] >= 5) {
			printf("%c", i + 'a');
			count++;
		}
	if (count == 0)
		cout << "PREDAJA";
	cout << endl;

}