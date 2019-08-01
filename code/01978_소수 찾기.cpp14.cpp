#include <iostream>
using namespace std;

int cnt = 0;
bool p[1001];
bool c[1001];

void prime(int n) {
	if (c[n])
		cnt++;
}


int main() {
	
	for (int i = 2; i <= 1000; i++) {
		if (p[i] == false)
			c[i] = true;
		for (int j = i*i; j <= 1000; j += i)
			p[j] = true;
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		prime(temp);
	}


	cout << cnt << endl;

}