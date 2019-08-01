// n 개중에 m개를 중복 있이 비내림차순으로 뽑음
// nHr 중복조합

#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
int n, m;

vector<int> v;
void dfs(int a) {
	if (v.size() == m) {
		for (auto x : v)
			cout << x << " ";
		cout << endl;
		return;
	}

	for (int i = a; i <= n; i++) {
		v.push_back(i);
		dfs(i);
		v.pop_back();
	}

}


int main() {
	cin >> n >> m;
	dfs(1);
}