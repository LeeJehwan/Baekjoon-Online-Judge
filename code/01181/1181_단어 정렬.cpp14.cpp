#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	set<string> s;
	while (n--) {
		string str;
		cin >> str;
		s.insert(str);
	}
	vector<string> v;
	for (auto i = s.begin(); i != s.end(); ++i) {
		v.push_back(*i);
	}

	sort(v.begin(), v.end(), [](string a, string b) {
		if (a.size() == b.size())
			return a < b;
		else
			return a.size() < b.size();
	});

	for (auto x : v)
		cout << x << endl;


}