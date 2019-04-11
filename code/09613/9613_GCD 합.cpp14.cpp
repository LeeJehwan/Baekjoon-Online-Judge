#include <iostream>
using namespace std;


int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}


void prob() {
	int n;
	cin >> n;

	int arr[101];
	for (int i = 0; i < n; i++) 
		cin >> arr[i];

	long long sum = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			sum += gcd(arr[i], arr[j]);
		}
	}
	cout << sum << '\n';

}




int main() {
	int t;
	cin >> t;
	while (t--) {
		prob();
	}
}