#include <stdio.h>

int main() {
	int num,i,codenum;
	int sum = 1;

	scanf("%d", &num);
	for (i = 0; i < num; i++){
		scanf("%d", &codenum);
		sum += codenum-1;
	}
	printf("%d\n", sum);

	return 0;
}