#include <iostream>
using namespace std;

bool arr[10005];

void self(int num) {
	if (num > 10000)
		return;
	if (arr[num])
		return;
	
	while (1) {
		int temp = num;
		while (1) {
			if (temp == 0)
				break;

			num += temp % 10;
			temp /= 10;
		}
		if (num > 10000)
			return;
		if (arr[num])
			return;
		arr[num] = true;
		
	}
}


int main() {
	for(int i=1;i<=10000;i++)
		self(i);


	for (int i = 1; i <= 10000; i++)
		if (!arr[i])
			cout << i << '\n';
}