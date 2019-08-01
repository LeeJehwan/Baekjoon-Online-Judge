#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>>v;

bool cmp(const pair<int, int>&v1,const pair<int, int>&v2) {
	return v1.second > v2.second;
}
int dist(const vector <pair<int, int>>&tmp, int n1, int n2) {
	int x = tmp[n1].first - tmp[n2].first;
	int y = tmp[n1].second - tmp[n2].second;
	return x*x + y*y;
}
int divideConquer(int start, int end) {
	int num = end - start + 1;
	if (num == 2)
		return dist(v, start, end);
	if (num == 3)
		return min({ dist(v,start,start + 1),dist(v,start,end),dist(v,start + 1,end) });

	int mid = (start + end) / 2;
	int min_L = divideConquer(start, mid);
	int min_R = divideConquer(mid + 1, end);
	
	int min_LR = min(min_L, min_R);

	vector<pair<int, int>>tmp;
	for (int i = start; i < end; i++ ) {
		int d = v[mid].first - v[i].first;
		if (d*d < min_LR)
			tmp.push_back(make_pair(v[i].first, v[i].second));
	}
	sort(tmp.begin(), tmp.end(), cmp);
	int len = tmp.size();
	for (int i = 0; i < len-1; i++) {
		for (int j = i + 1; j < len && j < i + 5; j++)
			min_LR = min(min_LR, dist(tmp, i, j));
	}
	return min_LR;
}


int main() {
	int num;
	cin >> num;
	int x, y;

	for (int i = 0; i < num; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end());

	cout << divideConquer(0, num - 1) << endl;
}