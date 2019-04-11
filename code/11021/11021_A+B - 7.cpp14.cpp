#include <iostream>
using namespace std;

int main() {
	int num1, num2;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &num1, &num2);
		cout << "Case #"<<i+1<<": "<<num1 + num2 << endl;
	}
	return 0;
}