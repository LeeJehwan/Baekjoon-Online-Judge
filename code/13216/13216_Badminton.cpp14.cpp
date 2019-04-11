#include <iostream>
#include <string>
using namespace std;

int main() {
	int count_a = 0;
	int count_b = 0;

	string str;
	cin >> str;
	int k = 0;
	for (int i = 0; i < 3; i++) {
		if (count_a == 2 || count_b == 2)
			break;

		int pa = 0, pb = 0;
		for (; k < 42*3; k++) {
			if (pa == 21 || pb == 21)
				break;
			if (str[k] == 'A')
				pa++;
			if (str[k] == 'B')
				pb++;
		}
		if (pa == 21)
			count_a++;
		if (pb == 21)
			count_b++;
		cout << pa << "-" << pb << '\n';
		pa = pb = 0;

	}

	if (count_a == 2)
		cout << "A" << '\n';
	if (count_b == 2)
		cout << "B" << '\n';
}
