#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int cnt[26];
int srt[26] = { -1, };
int main() {
	char s[5001];
	while (fgets(s,sizeof(s),stdin)) {
		int len = strlen(s);
		for (int i = 0; i <len; i++) {
			if(s[i]>='a' && s[i] <='z')
				cnt[s[i] - 'a']++;
		}
	}
	int max = cnt[0];
	int count = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > max)
			max = cnt[i];
	}
	for (int i = 0; i < 26; i++) {
		if (max == cnt[i])
			srt[count++] = i;
	}


	for (int i = 0; i < count; i++) {
			printf("%c", srt[i] + 'a');
	}
	cout << endl;
}
