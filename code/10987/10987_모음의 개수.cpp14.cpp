#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;

	char bowl[] = { 'a','e','i','o','u' };
	int count = 0;
	int len = str.size();
	for(int i=0;i<len;i++){
		for (int j = 0; j < 5; j++) {
			if (str[i] == bowl[j]) {
				count++;
				break;
			}
		}
	}
	cout << count << endl;
}