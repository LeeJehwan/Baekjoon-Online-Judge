#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
#define endl '\n'

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int a, b;
		cin >> a >> b;

		printf("You get %d piece(s) and your dad gets %d piece(s).\n",a/b,a%b);
	}
}