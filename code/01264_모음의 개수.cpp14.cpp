#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	char bowl[] = { 'a','e','i','o','u','A','E','I','O','U' };
	while (1) {
		string str;
		getline(cin, str);
		if (str == "#")
			break;
		int count = 0;
		int len = str.size();
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < 10; j++) {
				if (str[i] == bowl[j]) {
					count++;
					break;
				}
			}
		}
		cout << count << endl;
	}
	
}
