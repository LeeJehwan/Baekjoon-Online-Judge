#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	vector<int> v;
	
	while (1) {
		int t;
		int a = scanf("%d", &t);
		if (a==0 || a==EOF)
			break;
		v.push_back(t);
	}

	vector<int> v2;
	int len = v.size();
	for (int i = 0; i < len; i++)
		v2.push_back(v[i]);
	sort(v.begin(), v.end());

	for (int i = 0; i < len; i++) {
		if (v[i] != v2[i]) {
			cout << "Bad" << endl;
			return 0;
		}
	}
	cout << "Good" << endl;
}