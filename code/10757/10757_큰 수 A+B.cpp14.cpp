#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char a[100005];
char b[100005];
int main() {
	cin >> a;
	cin >> b;
	int a_size, b_size;
	for (int i = 0; ; i++) {
		if (a[i] == '\0') {
			a[i] = 0;
			a_size = i-1;
			break;
		}
	}
	for (int i = 0;; i++) {
		if (b[i] == '\0') {
			b[i] = 0;
			b_size = i-1;
			break;
		}
	}
	
	for (int i = 0; i <= a_size; i++)
		a[i] -= 48;
	for (int i = 0; i <= b_size; i++)
		b[i] -= 48;








	char c[100005];
	memset(c, 0, sizeof(c));
	int j = 0;
	for (int i = a_size; i >= 0; i--) {
		c[j++] = a[i];
	}
	j = 0;
	for (int i = b_size; i >= 0; i--) {
		c[j++] += b[i];
	}

	int k = max(a_size, b_size);
	for (int i =0; i < k; i++) {
		if (c[i] > 9) {
			c[i] -= 10;
			c[i + 1]++;
		}

	}

	if (c[k + 1] != 0) {
		k++;
	}

	
	for (int i = k; i >= 0; i--)
		printf("%d", c[i]);
	cout << endl;
}

