#include <iostream>
using namespace std;

const int MAX = 1000000;
int check[MAX+1];
int prime[MAX];
int pn = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 2; i <= MAX; i++) {
		if (check[i] == false)
			prime[pn++] = i;
		for (int j = i * 2; j <= MAX; j+=i)
			check[j] = true;
	}

	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		bool a = false;
		for (int i = 0; i < pn; i++) {
			if (check[n - prime[i]] == false) {
				cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
				a = true;
				break;
			}
		}
		if (a == false)
			cout << "Goldbach's conjecture is wrong." << '\n';

	}
}