#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	vector<int> v;
	for (int i = 1; i <= 5; i++) {
		string s;
		cin >> s;
		string str = "FBI";

		auto f = s.find(str);
		if (f != -1) {
			v.push_back(i);
		}

	}
	if (v.size() == 0)
		cout << "HE GOT AWAY!" << endl;
	else {
		for (auto x : v)
			cout << x << " ";
		cout << endl;
	}
	
}