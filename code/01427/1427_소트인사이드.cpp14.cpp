#include <iostream>
using namespace std;


int main() {
	char ch;
	int arr[10] = { 0 };
	int num;

	ch = getchar();
	num = ch - '0';
	arr[num]++;

	while((ch=getchar())!='\n') {
		//ch=getchar();
		num = ch - '0';
		arr[num]++;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < arr[i]; j++)
			cout <<i;
	}
	cout << endl;

	
}