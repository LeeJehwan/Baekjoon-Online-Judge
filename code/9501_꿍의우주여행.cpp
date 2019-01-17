#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, d;
		int cnt = 0;
		cin >> n >> d;
		for (int i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;

			double k = (double)b / c;
			double sum = k * (double)a;
			
			if (sum >= d)
				cnt++;

		}

		cout << cnt << endl;
	}

}