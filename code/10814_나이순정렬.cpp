#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;
#define endl '\n'

struct people {
	int age;
	string name;
};

bool cmp(const people &p1, const people &p2) {
	return p1.age < p2.age;
}

int main() {
	int n;
	cin >> n;
	
	vector<people> v;
	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		v.push_back({ age, name });
	}

	stable_sort(v.begin(), v.end(),cmp);

	for (auto x : v) {
		cout << x.age << " " << x.name << endl;
	}
}