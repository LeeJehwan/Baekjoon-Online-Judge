#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
#define endl '\n'

int a[501];
int a_sum[501];
int k;
vector<double> ans;


double mean(int s, int end) {
	int n = end - s + 1;
	return (double)(a_sum[end] - a_sum[s - 1]) / n;
}


void vari(int s, int end) {
	int n = end - s + 1;
	if (n < k)
		return;
	double m = mean(s, end);
	double sum = 0;
	for (int i = s; i <= end; i++) {
		sum += (a[i] - m)*(a[i] - m);
	}
	sum /= n;
	sum = sqrt(sum);
	ans.push_back(sum);
}




int main() {
	int n;
	cin >> n >> k;

	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		a_sum[i] = sum;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + k - 1; j <= n; j++) {
			vari(i, j);
		}
	}

	auto p = min_element(ans.begin(), ans.end());
	cout << fixed << setprecision(11) << *p << endl;

}
