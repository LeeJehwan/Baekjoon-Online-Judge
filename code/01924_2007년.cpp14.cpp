#include <iostream>
using namespace std;

int main() {
	int x, y;
	int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	cin >> x >> y;
	int sum=0;
	for (int i = 0; i < x - 1; i++)
		sum += arr[i];
	sum += y;
	int ret = sum % 7;
	switch (ret){
	case 0:
		cout << "SUN" << endl;;
		break;
	case 1:
		cout << "MON"<<endl;
		break;
	case 2:
		cout << "TUE" << endl;
		break;
	case 3:
		cout << "WED" << endl;
		break;
	case 4:
		cout << "THU" << endl;
		break;
	case 5:
		cout << "FRI" << endl;
		break;
	case 6:
		cout << "SAT" << endl;
		break;
	}
	return 0;
}