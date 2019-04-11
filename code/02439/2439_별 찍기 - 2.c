#include <stdio.h>

int main() {
	int num;
	int i, j;

	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		for (j = 1; j < num-i; j++)
			printf(" ");
		for (j = 0; j <= i; j++) {
			printf("%c", '*');
		}
		printf("\n");
	}
	return 0;
}