#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <tuple>
using namespace std;
#define endl '\n'

bool cmp(string str1, string str2) {
	return make_tuple(str1.size(), str1) < make_tuple(str2.size(), str2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<string> s;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}

	vector<string> v;
	for (auto x : s)
		v.push_back(x);

	sort(v.begin(), v.end(), cmp);

	for (auto x : v)
		cout << x << endl;


}