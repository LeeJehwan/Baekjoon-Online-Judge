#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

char star[5][9];
int list[13];
vector<pair<int, int>> v;
vector<int> v2;

bool chk() {
	int a1 = list[2] + list[3] + list[4] + list[5];
	int a2 = list[2] + list[6] + list[9] + list[12];
	int a3 = list[5] + list[7] + list[10] + list[12];
	int a4 = list[1] + list[3] + list[6] + list[8];
	int a5 = list[1] + list[4] + list[7] + list[11];
	int a6 = list[8] + list[9] + list[10] + list[11];

	if (a1 != 26) return false;
	if (a2 != 26) return false;
	if (a3 != 26) return false;
	if (a4 != 26) return false;
	if (a5 != 26) return false;
	if (a6 != 26) return false;

	return true;

}

void set_list(string str) {
	int i = 0; 
	for (int x : v2) {
		list[x] = str[i++] - 'A' + 1;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	string str, str2;
	int cnt = 1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> star[i][j];
			if (star[i][j] == 'x') {
				v.push_back({ i,j });
				v2.push_back(cnt);
				cnt++;
			}
			else if (star[i][j] != '.') {
				str2 += star[i][j];
				list[cnt] = star[i][j] - 'A' + 1;
				cnt++;
			}
		}
	}
	int len2 = str2.size();
	for (int i = 'A'; i <= 'L'; i++) {
		bool k = false;
		for (int j = 0; j < len2; j++) {
			if (i == str2[j])
				k = true;
		}
		if (!k)
			str += i;
	}

	do {
		set_list(str);
		if (chk())
			break;
	} while (next_permutation(str.begin(), str.end()));

	int i = 0;
	for (auto x : v) {
		star[x.first][x.second] = str[i++];
	}


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			cout << star[i][j];
		}
		cout << endl;
	}
	\
}



/*
....x....
.A.I.D.x.
..x...x..
.x.x.x.x.
....E....

*/