#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;


struct Student {
	string name;
	int lang;
	int eng;
	int math;
};

bool cmp(const Student &s1, const Student &s2) {
	return make_tuple(-s1.lang, s1.eng, -s1.math, s1.name) < make_tuple(-s2.lang, s2.eng, -s2.math, s2.name);
}

int main() {
	int n;
	cin >> n;
	vector<Student> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].lang >> v[i].eng >> v[i].math;
	}

	sort(v.begin(), v.end(), cmp);
	for (auto x : v) {
		cout << x.name << '\n';
	}
}