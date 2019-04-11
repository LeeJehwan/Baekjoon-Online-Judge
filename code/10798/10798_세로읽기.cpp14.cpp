#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	char arr[5][15];
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 15; j++)
			arr[i][j] = ' ';
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] == ' ' || arr[j][i] == '\0')
				continue;
			cout << arr[j][i];
		}
	}
	cout << endl;

}

