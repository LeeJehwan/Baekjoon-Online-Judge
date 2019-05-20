#include <iostream>	
using namespace std;
#define endl '\n'

int magnet[20];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n * 2; i++) {
		scanf("%1d", &magnet[i]);
	}

	bool ans = true;
	int temp = magnet[0];
	for (int i = 1; i < n * 2; i++) {
		if (temp == magnet[i]) {
			ans = false;
			break;
		}
		temp = magnet[i];
	}

	if (ans)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}