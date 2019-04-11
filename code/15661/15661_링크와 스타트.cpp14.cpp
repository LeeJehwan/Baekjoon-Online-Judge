#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int s[25][25];
int n;
long long ans = -1;

void go(int index, vector<int> &fi, vector<int> &se) {
	if (index == n) {
		if (fi.size() == 0)	return;
		if (se.size() == 0) return;
		long long f1_sum = 0, se_sum = 0;
		int len1 = fi.size();
		int len2 = se.size();

		for (int i = 0; i < len1 ; i++) {
			for (int j = 0 ; j < len1; j++) {
				f1_sum += s[fi[i]][fi[j]];
			}
		}

		for (int i = 0; i < len2; i++) {
			for (int j = 0; j < len2; j++) {
				se_sum += s[se[i]][se[j]];
			}
		}

		long long diff = abs(f1_sum - se_sum);
		if (ans == -1 || diff < ans)
			ans = diff;
		return;
	}

	fi.push_back(index);
	go(index + 1, fi, se);
	fi.pop_back();

	se.push_back(index);
	go(index + 1, fi, se);
	se.pop_back();
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> s[i][j];

	vector<int> fi;
	vector<int> se;
	go(0, fi, se);
	cout << ans << endl;
}