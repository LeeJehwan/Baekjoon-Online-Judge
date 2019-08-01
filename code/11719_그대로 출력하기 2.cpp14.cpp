#include <cstdio>

int main(){
	char str[101];
	char c;
	while ((c = getchar()) && c != EOF)
		printf("%c", c);
}