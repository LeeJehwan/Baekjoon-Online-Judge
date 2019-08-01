#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
#define endl '\n'

int n, m, q;
struct team {
	int solve;
	int point;
	int number;
};
int chk[101][16];
vector<team> v;

bool cmp(team t1, team t2) {
	return make_tuple(-t1.solve, t1.point, t1.number) < make_tuple(-t2.solve, t2.point, t2.number);
}


int main() {
	cin >> n >> m >> q;
	for (int i = 0; i <= n; i++) {
		team t = { 0,0,i };
		v.push_back(t);
	}

	while (q--) {
		int time, team_num, prob;
		string str;
		cin >> time >> team_num >> prob >> str;

		int& is_solve = chk[team_num][prob];
		if (str == "AC") {
			if (is_solve == 1) continue;
			int tmp = time + (-1)*is_solve * 20;
			v[team_num].point += tmp;
			v[team_num].solve += 1;
			is_solve = 1;
		}
		else {
			if (is_solve > 0)
				continue;
			is_solve--;
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i <= n; i++) {
		if (v[i].number == 0) continue;
		cout << v[i].number << " " << v[i].solve << " " << v[i].point << endl;
	}

}