#include <iostream>
using namespace std;


void run() {
	int price, num, option, num2;
	int sum = 0;

	cin >> price;
	sum += price;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> num2 >> option;
		sum += num2*option;
	}
	cout << sum << endl;
}
int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
		run();
}