#include <iostream>
#include <string>
#include <set>
using namespace std;
#define endl '\n'

bool ans = false;
bool end_flag = false;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int case_idx = 1;
	while (1) {
		int u, v;
		ans = false;
		set<int> s;
		int sum = 0;
		while (1) {
			cin >> u >> v;
			if (u < 0 && v < 0) {
				end_flag = true;
				break;
			}
			if (u == 0 && v == 0)
				break;
			
			s.insert(u);
			s.insert(v);
			sum++;
		}
		if (end_flag)break;
		

		if (sum == 0 || sum + 1 == s.size())
			ans = true;

		string str;
		if (ans)
			str = " is a tree.";
		else
			str = " is not a tree.";

		cout << "Case " << case_idx++ << str << endl;
	}

}