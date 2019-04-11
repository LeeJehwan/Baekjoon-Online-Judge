#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

string s;

bool cmp(const int &u, const int &k) {
	return strcmp(s.c_str() + u, s.c_str() + k) < 0;
}


int main() {
	cin >> s;

	int len = s.size();
	vector<int> v;
	for (int i = 0; i < len; i++)
		v.push_back(i);

	sort(v.begin(), v.end(), cmp);

	for (auto x : v)
		cout << s.substr(x) << endl;
}