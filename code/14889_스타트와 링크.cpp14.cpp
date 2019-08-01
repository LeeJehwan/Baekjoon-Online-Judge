#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int ability[21][21];
#define endl '\n'

vector<int> ans;

int calc(const vector<int> &first,const vector<int> &second) {
	int sum1 = 0;
	for (int i = 0; i < n/2; i++) {
		for (int j = 0; j < n / 2; j++) {
			sum1 += ability[first[i]][first[j]];
		}
	}
	int sum2 = 0;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			sum2 += ability[second[i]][second[j]];
		}
	}
	return abs(sum1 - sum2);
}




void go(int index, vector<int> &first, vector<int> &second) {
	if (first.size() > n / 2)
		return;
	if (second.size() > n / 2)
		return;
	if (index == n+1) {
		ans.push_back(calc(first, second));
		return;
	}
	

	first.push_back(index);
	go(index + 1, first, second);
	first.pop_back();
	second.push_back(index);
	go(index + 1, first, second);
	second.pop_back();
}


int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> ability[i][j];
		}
	}

	vector<int> first;
	vector<int> second;
	go(1, first, second);

	cout << *min_element(ans.begin(), ans.end()) << endl;
}