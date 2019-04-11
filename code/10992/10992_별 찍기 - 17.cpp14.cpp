#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	for (int i = 0; i < num-1; i++) {
		for (int k = num-i; k > 1; k--)
			cout << " ";
		cout << "*";
		bool con = false;
		for (int h = 0; h < 2 * i - 1; h++) {
			cout << " ";
			con = true;
		}
		if (con == 1)
			cout << "*";
		
		cout << endl;
	}
	for (int i = 0; i < 2*num-1; i++)
		cout << "*";
	cout << endl;
	
}