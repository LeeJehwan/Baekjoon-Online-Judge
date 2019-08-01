#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct Person {
	int age;
	string name;
};

bool cmp(const Person &p1, const Person &p2) {
	return p1.age < p2.age;
}



int main() {
	int n;
	cin >> n;
	vector<Person> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].age;
		cin >> p[i].name;
	}

	stable_sort(p.begin(),p.end(),cmp);
	for (int i = 0; i < n; i++) {
		cout << p[i].age << " " << p[i].name << '\n';
	}
}