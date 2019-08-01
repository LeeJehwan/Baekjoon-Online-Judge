#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
	string name;
	int lang;
	int eng;
	int math;
};

bool cmp(const Student &s1, const Student &s2) {
	if (s1.lang > s2.lang)
		return true;
	else if (s1.lang == s2.lang) {
		if (s1.eng < s2.eng)
			return true;
		else if (s1.eng == s2.eng) {
			if (s1.math > s2.math)
				return true;
			else if(s1.math == s2.math)
				return s1.name < s2.name;
		}
	}
	return false;
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