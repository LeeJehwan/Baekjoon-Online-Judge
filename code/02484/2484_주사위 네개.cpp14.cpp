#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dice(int a, int b, int c, int d) {
	if (a == b && b == c && c == d)			//ABCD
		return 50000 + a * 5000;
	if (a == b && (b == c || b == d))		//ABC ABD
		return 10000 + a * 1000;
	if (a == c && c == d)					//ACD
		return 10000 + a * 1000;
	if (b == c && c == d)					//BCD
		return 10000 + b * 1000;
	if (a == b && c == d)					//AB CD
		return 2000 + a * 500 + c * 500;
	if (a == c && b == d)					//AC BD
		return 2000 + a * 500 + b * 500;
	if (a == d && b == c)
		return 2000 + a * 500 + b * 500;
	if (a == b || a == c || a == d)			//AB AC AD
		return 1000 + a * 100;
	if (b == c || b == d)					//BC BD
		return 1000 + b * 100;
	if (c == d)								//CD
		return 1000 + c * 100;
	return max({ a,b,c,d }) * 100;
}


int main(){
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		arr[i] = dice(a, b, c, d);
	}
	cout << *max_element(arr, arr + n) << endl;
}