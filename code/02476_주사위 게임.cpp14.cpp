#include <iostream>
#include <algorithm>
using namespace std;

int dice(int a, int b, int c) {
	if (a == b && b == c)
		return 10000 + a * 1000;
	if (a == b || a==c)
		return 1000 + a * 100;
	if (b == c)
		return 1000 + b * 100;
	return max({ a,b,c }) * 100;
}


int arr[1000];
int main(){
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[i] = dice(a, b, c);
	}
	cout << *max_element(arr, arr + n) << endl;
}