// n 개중에 m개를 중복 있이 순서 상관 고려해서 뽑음
// nㅠm

#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
int n, m;

vector<int> v;
void dfs() {
	if (v.size() == m) {
		for (auto x : v)
			cout << x << " ";
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		dfs();
		v.pop_back();
	}

}


int main() {
	cin >> n >> m;
	dfs();
}