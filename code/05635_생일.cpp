#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;

struct stu {
	int a, b, c;
	string name;
};

bool cmp(stu s1, stu s2) {
	return make_tuple(s1.a, s1.b, s1.c) < make_tuple(s2.a, s2.b, s2.c);
}

int main() {
	int n;
	cin >> n;
	vector <stu> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].c >> v[i].b >> v[i].a;
	}
	
	sort(v.begin(), v.end(), cmp);
	cout << v[n-1].name << endl;
	cout << v[0].name << endl;
}