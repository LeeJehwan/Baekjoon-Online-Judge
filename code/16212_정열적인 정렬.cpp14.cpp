#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int arr[500001];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}