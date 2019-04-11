#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#define endl '\n'

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> q;

	int n;
	cin >> n;

	while (n--) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			if (q.empty())
				cout << 0 << endl;
			else {
				cout << q.top().second << endl;
				q.pop();
			}
		}
		else {
			q.push({ abs(tmp), tmp });
		}
	}
	
}