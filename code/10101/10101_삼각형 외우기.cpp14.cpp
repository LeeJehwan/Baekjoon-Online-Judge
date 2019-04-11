#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int a, b, c;
	cin >> a >> b >> c;
	int sum = a + b + c;
	if (sum != 180) {
		cout << "Error" << endl;
		return 0;
	}

	if (a == 60 && b == 60 && c == 60)
		cout << "Equilateral" << endl;
	else if (a == b || a == c || b == c)
		cout << "Isosceles" << endl;
	else
		cout << "Scalene" << endl;
	

}