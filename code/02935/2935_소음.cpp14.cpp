#include <iostream>
#include <algorithm>
using namespace std;


int find_zero(char str[]) {
	int i = 0;
	while (1) {
		if (str[i] == '\0')
			break;
		i++;
	}
	return i;
}



int main() {
	char str1[101];
	char str2[101];
	char a;
	cin >> str1 >> a >> str2;

	int t1, t2;
	t1 = find_zero(str1);
	t2 = find_zero(str2);

	if (a == '*') {
		cout << 1;
		for (int i = 0; i < t1 + t2 - 2; i++)
			cout << 0;
		cout << endl;
	}
	else if (a == '+') {
		if (t1 == t2) {
			cout << 2;
			for (int i = 0; i < t1 - 1; i++)
				cout << 0;
			cout << endl;
		}
		else {
			int max_t, min_t;
			max_t = max(t1, t2);
			min_t = min(t1, t2);
			cout << 1;
			int temp = max_t - 1 - min_t;
			for (int i = 0; i < temp; i++)
				cout << 0;
			cout << 1;
			for (int i = 0; i < min_t - 1; i++)
				cout << 0;
			cout << endl;
		}
	}
}