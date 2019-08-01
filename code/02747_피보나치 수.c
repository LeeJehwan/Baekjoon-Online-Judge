#include <stdio.h>

int main() {
	int arr[45];
	int i, num;
	
	scanf("%d", &num);

	for (i = 0; i < num+1; i++) {
		if (i < 2) {
			arr[0] = 0; arr[1] = 1;
		}
		else
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
	}
	printf("%d\n", arr[num]);
}