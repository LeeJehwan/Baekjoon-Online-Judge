#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
	int cc;
	cin >> cc;
	while (cc--) {
		int n;
		cin >> n;
		int t = (n + 1) / 2;
		cout << t * t << endl;
	}

}