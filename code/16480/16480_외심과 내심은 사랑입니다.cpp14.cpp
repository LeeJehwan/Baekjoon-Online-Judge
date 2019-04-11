#include <iostream>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	long long ans = a * a - 2 * a*b;
	cout << ans << endl;
}