#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
#define endl '\n'


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		long long tmp = 1;
		int idx = 1;
		while (1) {
			if (tmp % n == 0) {
				cout << idx << endl;
				break;
			}
			tmp = tmp % n;
			tmp = tmp * 10 + 1;
			idx++;
		}
	}
}