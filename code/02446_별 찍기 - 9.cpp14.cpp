#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	for (int i = num; i >0; i--) {
		for (int j = num; j > i; j--) 
			cout<<" ";
		for (int j = 0; j < 2 * i - 1; j++)
			cout << "*";
		cout << endl;
	}

	for (int i = 1; i < num; i++) {
		for (int j = 1; j < num - i; j++)
			cout << " ";
		for (int j = 0; j < 2 * i + 1; j++)
			cout << "*";
		cout << endl;
	}
	
	
}