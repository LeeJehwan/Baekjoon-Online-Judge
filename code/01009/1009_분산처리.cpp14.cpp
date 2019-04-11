#include <iostream>
using namespace std;


void mod() {
	int a, b, c;
	cin >> a >> b;
	if (b < 10) {
		int temp;
		int a_temp=1;
		for (int i = 0; i < b; i++) {
			temp = (a*a_temp) % 10;
			a_temp = temp;
		}
		cout << temp<<endl;
	}
	else {
		int temp;
		int a_temp = 1;
		for (int i = 0; i < b; i++) {
			temp = (a*a_temp) % 10;
			a_temp = temp;
			if (i!=0 && temp == a%10) {
				c = i;
				break;
			}
		}
		b = b%c;
		if (b == 0)
			b = c;
		a_temp = 1;
		for (int i = 0; i < b; i++) {
			temp = (a*a_temp) % 10;
			a_temp = temp;
		}
		if (temp == 0) {
			cout << 10 << endl;
			return;
		}
		cout << temp << endl;
	}
}


int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
		mod();
}