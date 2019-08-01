#include <iostream>
using namespace std;
#define endl '\n'

int arr[51][2];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
				cnt++;
		}
		cout << cnt << " ";
	}
	
}