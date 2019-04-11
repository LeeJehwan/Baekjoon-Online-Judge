#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int num) {
	int count = 0;
	for (int i = 1; i <= num; i++) {
		if (num%i == 0)
			count++;
	}
	if (count > 2) {
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
}


int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int a;
		cin >> a;
	}
	solve(num);
}

