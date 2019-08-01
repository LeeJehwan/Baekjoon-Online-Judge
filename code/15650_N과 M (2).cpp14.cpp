// n 개중에 m개를 중복 없이 순서 상관 없이 뽑음
// nCm 

#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

vector<int> v;
int n, m;
void dfs(int a) {
	if (v.size() == m) {
		for(int x : v)
			cout << x << " ";
		cout << endl;
		return;
	}

	for (int i = a; i <= n; i++) {
		if (v.size() < m) {
			v.push_back(i);
			dfs(i+1);
			v.pop_back();
		}
	}
}


int main() {
	cin >> n >> m;
	dfs(1);
}