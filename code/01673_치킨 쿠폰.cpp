#include <iostream>
#include <cstdio>
using namespace std;

int cal(int n, int k) {
	int ret = n;
	int n2;
	while (n>=k) {
		n2 = n % k;
		n = n / k ;
		ret += n;
		n += n2;
	}

	return ret;
}

int main() {
	int n, k;
	while (1) {
		if (scanf("%d %d", &n, &k) == -1)
			break;
		cout << cal(n, k) << endl;

		
	}
	return 0;
}