#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
	int n;
	scanf("%d", &n);


	int i = 0;
	while (i < n) 
	{
		int j = 0;
		while (j < i+1)
		{
			printf("*");
			j++;
		}
		printf("\n");
		i++;
	}


}