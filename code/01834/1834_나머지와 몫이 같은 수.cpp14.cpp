#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long n;
	cin >> n;
	long long sum = 0;
	for (long long i = 1; i < n; i++) {
		long long tmp = i*n + i;
		sum += tmp;
	}
	cout << sum << endl;
	
	
}
