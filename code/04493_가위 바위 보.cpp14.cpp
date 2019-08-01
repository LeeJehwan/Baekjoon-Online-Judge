#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int RSP(char A, char B) {
	if (A == B)
		return 0;
	if (A == 'R' && B == 'S')
		return 1;
	if (A == 'R' && B == 'P')
		return 2;
	if (A == 'S' && B == 'R')
		return 2;
	if (A == 'S' && B == 'P')
		return 1;
	if (A == 'P' && B == 'R')
		return 1;
	if (A == 'P' && B == 'S')
		return 2;
}





int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int cnt_A = 0, cnt_B = 0;
		for (int i = 0; i < n; i++) {
			char A, B;
			cin >> A >> B;
			int ans = RSP(A, B);
			if (ans == 1)
				cnt_A++;
			if (ans == 2)
				cnt_B++;
			
		}
		if (cnt_A == cnt_B) {
			cout << "TIE" << endl;
		}
		else if (cnt_A > cnt_B) {
			cout << "Player 1" << endl;
		}
		else
			cout << "Player 2" << endl;

	}
}