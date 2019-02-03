#include <iostream>
#include <string>
#include <vector>
using namespace std;

int word[51];

void sol(int idx = 0) {





}


int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (auto s : str) {
			word[i] |= (1 << s);
		}
	}


}