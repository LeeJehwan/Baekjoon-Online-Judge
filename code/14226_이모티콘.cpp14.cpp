#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
using namespace	std;
#define endl '\n'

bool chk[1005][1005];
int time[1005][1005];
int main(){
	int n;
	cin >> n;

	queue<pair<int, int>> q;
	q.push({ 1,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == n)
			break;
		
		int t1, t2;
		
		t1 = x;
		t2 = x;
		if (t1<=1000 && t2<= 1000 && !chk[t1][t2]) {
			q.push({ t1,t2 });
			chk[t1][t2] = true;
			time[t1][t2] = time[x][y] + 1;
		}

		t1 = x + y;
		t2 = y;
		if (t1 <= 1000 && t2 <= 1000 && !chk[t1][t2]) {
			q.push({ t1,t2 });
			chk[t1][t2] = true;
			time[t1][t2] = time[x][y] + 1;
		}
		
		t1 = x - 1;
		t2 = y;
		if (t1 >= 0 && t2 >= 0 && !chk[t1][t2]) {
			q.push({ t1,t2 });
			chk[t1][t2] = true;
			time[t1][t2] = time[x][y] + 1;
		}
	}
	int ans = 1000000000;
	for (int i = 0; i <= 1000; i++) {
		if (chk[n][i])
			ans = min(ans, time[n][i]);
	}
	cout << ans << endl;
}