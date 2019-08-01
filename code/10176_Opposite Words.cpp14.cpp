#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define endl '\n'

int arr[13];

int main() {
	int t;
	cin >> t;
	getchar();


	while (t--) {
		string str;
		getline(cin, str);
		memset(arr, 0, sizeof(arr));
		int len = str.size();

		for (int i = 0; i < len; i++) {
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 'a' - 'A';
		}
		
		bool key = true;

		for (int i = 0; i < len; i++) {
			if (str[i] > 'M')
				str[i] = 'A' - (str[i] - 'Z');

			arr[str[i] - 'A']++;
		}

		for (int i = 0; i < 13; i++) {
			if (arr[i] == 1)
				key = false;
		}


		if (key)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

}