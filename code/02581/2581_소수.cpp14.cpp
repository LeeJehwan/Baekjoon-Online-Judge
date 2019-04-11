#include <iostream>
using namespace std;

int d[10001];
int prime[10001];
int cnt = 0;
void eratos() {
	for (int i = 2; i <= 10000; i++) {
		if(d[i]==false)
			prime[cnt++] = i;
		for (int j = i * 2; j <= 10000; j+=i)
			d[j] = true;
	}
}


int main() {
	eratos();
	int min = 0;
	int sum = 0;
	int m, n;
	cin >> m >> n;
	
	for (int i = 0; i < cnt; i++) {
		if (prime[i] > n)
			break;
		if (prime[i] >= m) {
			if (min == 0)
				min = prime[i];
			sum += prime[i];
		}
	}

	if (min == 0) {
		cout << -1 << endl;
		return 0;
	}

	cout << sum << endl;
	cout << min << endl;

}