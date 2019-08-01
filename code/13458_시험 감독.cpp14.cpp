#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int p[1000001];
int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	int b, c;
	cin >> b >> c;

	long long cnt = n;
	for (int i = 0; i < n; i++) {
		p[i] -= b;
	}

	for (int i = 0; i < n; i++) {
		if (p[i] <= 0)
			continue;
		int tmp = (p[i] / c);
		if (p[i] % c != 0)
			tmp += 1;
		cnt += tmp;
	}

	cout << cnt << endl;
}