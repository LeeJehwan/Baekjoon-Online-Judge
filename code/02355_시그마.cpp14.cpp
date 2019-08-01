#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define endl '\n'


void cal(long long A, long long B) {
	long long dis = B - A + 1;
	long long sum = dis*A;
	dis--;
	long long sum2 = (dis*(dis + 1)) / 2;

	long long ans = sum + sum2;
	cout << ans << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, b;
	cin >> a >> b;
	long long A, B;
	A = min(a, b);
	B = max(a, b);
	if (A < 0 && B < 0) {
		cal(A, B);
	}
	else if (A < 0 && B>0) {
		if (abs(A) > B) {
			cal(A, -B - 1);
		}
		else {
			cal(-A + 1, B);
		}
	}
	else
		cal(A, B);
	
	
	
}

