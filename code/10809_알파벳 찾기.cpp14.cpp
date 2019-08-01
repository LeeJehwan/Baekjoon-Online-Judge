#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	string s;
	cin >> s;

	for (int i = 'a'; i <= 'z'; i++) {
		int t = s.find(i);
		if (t != -1)
			cout << t << ' ';
		else
			cout << -1 << ' ';
	}
		
	cout << endl;
}