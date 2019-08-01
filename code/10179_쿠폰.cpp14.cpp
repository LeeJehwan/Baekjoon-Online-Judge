#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
#define endl '\n'

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		double a;
		cin >> a;
		printf("$%.2lf\n", a*0.8);
	}
}