#include <iostream>
#include <vector>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> ii;

int ccw(ii v1, ii v2, ii v3) {
	int ret = (v1.first*v2.second + v2.first*v3.second + v3.first*v1.second)
		- (v2.first*v1.second + v3.first * v2.second + v1.first * v3.second);

	if (ret < 0)
		return -1;
	else if (ret == 0)
		return 0;
	else
		return 1;
}

bool chkIntersection(ii A, ii B, ii C, ii D) {
	int tmp1 = ccw(A, B, C) * ccw(A, B, D);
	int tmp2 = ccw(C, D, A) * ccw(C, D, B);

	if (tmp1 == 0 && tmp2 == 0) {
		if (A > B) swap(A, B);
		if (C > D) swap(C, D);

		return A <= D && C <= B;
	}
	return tmp1 <= 0 && tmp2 <= 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		ii left, right;
		ii start, end;

		cin >> start.first >> start.second;
		cin >> end.first >> end.second;
		cin >> left.first >> left.second;
		cin >> right.first >> right.second;

		if (left > right)swap(left, right);
		if (start > end) swap(start, end);

		ii left2, right2;
		left2.first = left.first;
		left2.second = right.second;
		right2.first = right.first;
		right2.second = left.second;

		int sum = 0;
		sum += chkIntersection(start, end, left, left2);
		sum += chkIntersection(start, end, left, right2);
		sum += chkIntersection(start, end, right, right2);
		sum += chkIntersection(start, end, right, left2);
		if (sum) {
			cout << 'T' << endl;
			continue;
		}

		if (left > left2) swap(left, left2);
		if (right2 > right) swap(right, right2);

		if (left.first <= start.first && end.first <= right.first) {
			if (start.second > end.second) swap(start, end);
			if (left.second <= start.second && end.second <= right.second) {
				cout << 'T' << endl;
				continue;
			}
		}

		cout << 'F' << endl;
	}
}