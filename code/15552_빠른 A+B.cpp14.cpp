#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int testNum, num1, num2;
	cin >> testNum;

	for (int i = 0; i < testNum; i++){
		cin >> num1 >> num2;
		cout << num1 + num2 << "\n";
	}
	return 0;
}