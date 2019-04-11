#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
using namespace	std;
#define endl '\n'


int main() {
	string a, b;
	cin >> a >> b;

	int len1 = a.size();
	for (int i = 0; i < len1; i++)
		if (a[i] == '6')
			a[i] = '5';
	int len2 = b.size();
	for (int i = 0; i < len2; i++)
		if (b[i] == '6')
			b[i] = '5';
	int t1 = stoi(a);
	int t2 = stoi(b);
	cout << t1 + t2 << " ";

	for (int i = 0; i < len1; i++)
		if (a[i] == '5')
			a[i] = '6';
	for (int i = 0; i < len2; i++)
		if (b[i] == '5')
			b[i] = '6';

	t1 = stoi(a);
	t2 = stoi(b);
	cout << t1 + t2 << endl;

	
}