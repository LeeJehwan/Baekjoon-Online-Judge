#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool check(string &pass) {
	int ja = 0;
	int mo = 0;
	for (char x : pass) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
			mo += 1;
		else
			ja += 1;
	}
	return ja >= 2 && mo >= 1;

}


void go(int n, vector<char> &v, string pass, int i) {
	if (pass.length() == n) {
		if (check(pass))
			cout << pass << '\n';
		return;
	}

	if (i == v.size()) return;
	go(n, v, pass + v[i], i + 1);
	go(n, v, pass, i + 1);
}


int main() {
	int n, m;
	cin >> n >> m;

	vector<char> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	go(n, v, "", 0);
	
}
