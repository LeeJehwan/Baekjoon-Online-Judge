#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%1d", &num);
		sum += num;
	}
	cout << sum << endl;
}