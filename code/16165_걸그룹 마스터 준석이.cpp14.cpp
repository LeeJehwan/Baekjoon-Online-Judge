#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define endl '\n'

int main() {
	int n, m;
	cin >> n >> m;

	multimap<string, string> map;
	unordered_map<string, string> map2;
	for (int i = 0; i < n; i++) {
		string team;
		cin >> team;
		int j = 0;
		cin >> j;
		while (j--) {
			string name;
			cin >> name;
			map.insert(make_pair(team, name));
			map2[name] = team;
		}
	}

	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		bool type;
		cin >> type;
		if (type) {
			if(map2.count(tmp))
				cout << map2[tmp] << endl;
		}
		else{
			if (map.count(tmp)) {
				vector<string> ans;
				for (auto it = map.equal_range(tmp).first; it != map.equal_range(tmp).second; ++it)
					ans.push_back(it->second);
				sort(ans.begin(), ans.end());
				for (auto x : ans)
					cout << x << endl;;
			}
		}


	}

}