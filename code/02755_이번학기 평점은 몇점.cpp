#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	int n;
	cin >> n;

	double sum = 0;
	int cnt = 0;
	string str[13] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D+", "D0", "D-", "F" };
	double g[13] = { 4.3, 4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 1.3, 1.0, 0.7, 0.0 };
	for (int i = 0; i < n; i++) {
		string s, b;
		int a;
		cin >> s >> a >> b;
		int j;
		for (j = 0; j < 13; j++) 
			if (str[j] == b) break;
		sum += g[j]*a;
		cnt += a;
	}
	double ans = sum / cnt + 0.00000001;
	cout << fixed << setprecision(2) << ans << endl;

}