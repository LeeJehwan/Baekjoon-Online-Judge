#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'

vector<string> v;
bool cmp(string s1, string s2) {
	int len1 = s1.size();
	int len2 = s2.size();

	if (len1 > len2) return false;
	else if (len1 < len2) return true;

	int sum1 = 0, sum2 = 0;
	for (char x : s1) {
		if (x >= '0' && x <= '9')
			sum1 += (int)(x-'0');
	}
	for (char x : s2) {
		if (x >= '0' && x <= '9')
			sum2 += (int)(x - '0');
	}

	if (sum1 > sum2) return false;
	else if (sum1 < sum2) return true;

	if (s1 > s2)
		return false;
	else
		return true;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	
	sort(v.begin(),v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i] << endl;
	}
}

