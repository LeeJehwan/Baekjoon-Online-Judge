#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
int n, k;
int a[50];
int ans = 0;

void go(int count, int word, vector<char> v, int v_count) {
	if (count == k || v_count == v.size()) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if ((a[i] & ((1 << 26) - 1 - word)) == 0) {
				sum++;
			}
		}
		ans = max(ans, sum);
		return;
	}

	for (int i = v_count; i < v.size(); i++) {
		word |= (1 << (v[i] - 'a'));
		go(count + 1, word, v, i + 1);
		word &= (~(1 << (v[i] - 'a')));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	k -= 5;
	if (k < 0) {
		cout << ans << endl;
		return 0;
	}
	
	int word = 0;
	word |= (1 << ('a' - 'a'));
	word |= (1 << ('n' - 'a'));
	word |= (1 << ('t' - 'a'));
	word |= (1 << ('i' - 'a'));
	word |= (1 << ('c' - 'a'));

	set<char> s;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int tmp = 0;
		for (auto x : str) {
			tmp |= (1 << (x - 'a'));
			s.insert(x);
		}
		a[i] = tmp;
	}

	vector<char> v;
	for (auto x : s) {
		if (x == 'a' || x == 'n' || x == 't' || x == 'i' || x == 'c')
			continue;
		v.push_back(x);
	}

	go(0, word, v, 0);
	cout << ans << endl;
}