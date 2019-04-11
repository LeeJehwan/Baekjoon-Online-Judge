#include <iostream>
using namespace std;
int main() {
	int a, b, v;
	cin >> a >> b >> v;

	int count = 0;
	int sum = v - a;
	int sub = a - b;
	count += sum / sub;
	if (sum - count*sub > 0)
		count++;
	count++;


	cout << count << endl;
}
