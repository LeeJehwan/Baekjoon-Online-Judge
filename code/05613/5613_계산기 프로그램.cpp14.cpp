#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int calc(int a, int b, char op) {
	if (op == '+')
		return a + b;
	if (op == '-')
		return a - b;
	if (op == '*')
		return a*b;
	if (op == '/')
		return a / b;
}



int main() {
	vector<int> v;
	vector<char> op;
	while (1) {
		int t;
		cin >> t;
		v.push_back(t);
		char c;
		cin >> c;
		if (c == '=')
			break;
		op.push_back(c);
		
	}

	int tmp = v[0];
	int len = op.size();

	for (int i = 1; i <= len; i++) {
		tmp = calc(tmp, v[i], op[i - 1]);
	}
	cout << tmp << endl;

}