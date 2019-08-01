#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define endl '\n'

int price1[101];
int price2[65];
int main() {
	price1[1] = 500;
	price1[2] = 300;
	price1[3] = 300;
	price1[4] = 200;
	price1[5] = 200;
	price1[6] = 200;
	for (int i = 0; i < 4; i++) {
		price1[7 + i] = 50;
	}
	for (int i = 0; i < 5; i++) {
		price1[11 + i] = 30;
	}for (int i = 0; i < 6; i++) {
		price1[16 + i] = 10;
	}
	price2[1] = 512;
	price2[2] = 256;
	price2[3] = 256;
	for (int i = 0; i < 4; i++) {
		price2[4 + i] = 128;
	}
	for (int i = 0; i < 8; i++) {
		price2[8 + i] = 64;
	}
	for (int i = 0; i < 16; i++) {
		price2[16 + i] = 32;
	}

	int t;
	cin >> t;

	while (t--) {
		int sum = 0;
		int a, b;
		cin >> a >> b;
		sum = price1[a] + price2[b];
		cout << sum*10000 << endl;
	}

}
