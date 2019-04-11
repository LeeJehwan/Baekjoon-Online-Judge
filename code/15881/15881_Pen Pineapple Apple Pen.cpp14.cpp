#include <iostream>
#include <string>
using namespace std;


int main() {
	int n;
	cin >> n;
	int count = 0;
	string str;
	cin >> str;
	int step = 1;
	for (int i = 0; i < n; i+=step) {
		if (str[i] == 'p') {
			if (i + 3 < n) {
				if (str[i + 1] == 'P' && str[i + 2] == 'A' && str[i + 3] == 'p') {
					count++;
					step = 4;
					continue;
				}
			}
		}
		step = 1;

	}



	cout << count << '\n';
}