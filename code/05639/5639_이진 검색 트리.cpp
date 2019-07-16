#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int a[10005];

void solve(int s, int e) {
	if (s > e)
		return;
	int root = a[s];
	int l = s;

	while (l <= e && root >= a[l]) {
		l++;
	}
	solve(s + 1, l - 1);
	solve(l, e);
	printf("%d\n", root);
}


int main() {
	int i = 0;
	while (scanf("%d", &a[i++]) != -1);

	solve(0, i - 2);
}