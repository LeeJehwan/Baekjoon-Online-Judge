#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
int n;
int cnt = 0;
bool ok[15];
vector<int> v;
bool chk(int index) {
	for (int i = 0; i < index; i++) {
		if (v[index] == v[i])
			return false;
		if ((index-i) + v[i] == v[index])
			return false;
		if ((v[i] - (index - i)) == v[index])
			return false;
	}
	
	return true;
}


void go(int index) {
	if (n == index) {
		cnt++;
	}
	for (int i = 0; i < n; i++) {
		if (ok[i])
			continue;

		v.push_back(i);
		if (chk(index))
			go(index + 1);
		v.pop_back();
	}
}



int main() {
	cin >> n;
	go(0);
	cout << cnt << endl;
}