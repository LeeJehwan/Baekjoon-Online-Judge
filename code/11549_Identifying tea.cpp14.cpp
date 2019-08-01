#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
	int ans; 
	cin >> ans;
	int cnt = 0;
	int arr[5];
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		if (arr[i] == ans)
			cnt ++;
	}

	cout << cnt << endl;
	

}