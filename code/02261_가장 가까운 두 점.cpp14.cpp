#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> v;

bool cmp(const pair<int, int> &v1, const pair<int, int> &v2) {
	return v1.second > v2.second;
}

int dist(const vector<pair<int,int>>&tmp, int n1, int n2) {
	int x = tmp[n1].first - tmp[n2].first;
	int y = tmp[n1].second - tmp[n2].second;
	return x*x + y*y;
}

int divideConquer(int start, int end) {
	int min_R, min_L;
	int mid = (start + end) / 2;
	int count = end - start + 1;

	if (count == 2)
		return dist(v,start, end);
	if (count == 3)
		return min({ dist(v,start, start + 1), dist(v,start, end), dist(v,start + 1, end) });
	min_L = divideConquer(start, mid);
	min_R = divideConquer(mid + 1, end);
	int min_LR = min(min_L, min_R);

	vector<pair<int, int>>temp;

	for (int i = start; i < end; i++) {
		int d = v[mid].first - v[i].first;
		if (d*d < min_LR)
			temp.push_back(v[i]);
	}
	sort(temp.begin(), temp.end(), cmp);
	int len = temp.size();
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len && j < i + 7; j++)
			min_LR = min(min_LR, dist(temp, i, j));
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
	cout<<divideConquer(0, num - 1)<<endl;
}