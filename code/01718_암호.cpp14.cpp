#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
	char str1[32010];
	char str2[32010];
	char ans[32010];
	char ch;
	int str1_len = 0;
	
	fgets(str1, sizeof(str1), stdin);
	cin >> str2;
	str1_len = strlen(str1);
	int str2_len = strlen(str2);
	int t;
	for (int i = 0; i < str1_len-1; i++) {
		t = i%str2_len;
		ans[i] = str1[i] - str2[t]+'a'-1;
		if (str1[i] == ' ') 
			ans[i] = ' ';
		else if (ans[i] < 'a')
			ans[i] += 26;
		else if (ans[i] > 'z')
			ans[i] -= 26;
	}
	ans[str1_len] = '\0';
	cout << ans << endl;
	return 0;
}