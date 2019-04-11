#include <iostream>
#include <vector>
using namespace std;
#define MAX 123456*3

vector<int> v;
bool chk[MAX+1];
void eratos() {
	for (int i = 2; i <= MAX; i++) {
		if (chk[i] == 0) {
			v.push_back(i);
			for (int j = i * 2; j <= MAX; j += i)
				chk[j] = 1;
		}
	}
}

int main() {
	eratos();
	while (1) {
		int t;
		cin >> t;
		if (t == 0)
			break;

		int count = 0;
		for (int i = 0; ; i++) {
			if (v[i] <= t)
				continue;
			if (v[i] > 2 * t)
				break;
			count++;
		}
		cout << count << endl;
	}
}