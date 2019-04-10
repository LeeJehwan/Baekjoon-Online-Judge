#include <cstdio>

int main() {
	int num1, num2, num3, num4;
	int result1, result2, result3;

	scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
	result1 = num3 - num1;
	result2 = num4 - num2;

	if (result1 > num1)
		result1 = num1;
	if (result2 > num2)
		result2 = num2;
	if (result1 > result2)
		result3 = result2;
	else
		result3 = result1;

	printf("%d\n", result3);

	return 0;
}