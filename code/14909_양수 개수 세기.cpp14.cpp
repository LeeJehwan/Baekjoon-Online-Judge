#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int count = 0;
	int num;
		while (scanf("%d", &num) != EOF) {
			if (num > 0)
				count++;
		}
	
	cout << count << endl;
}