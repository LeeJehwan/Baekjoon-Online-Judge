#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	multiset<char> se[101];
	for(int j = 0 ;j < n ;j++) {
		string s;
		cin >> s;
		int len = s.size();
		for (int i = 0; i < len; i++)
			se[j].insert(s[i]);
	}
	set<multiset<char>> real_set;
	for (int i = 0; i< n; i++ ) {
		real_set.insert(se[i]);
	}
	
	cout << real_set.size() << endl;

}