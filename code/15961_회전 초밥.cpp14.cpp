#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int eat[3005];
int sushi[3003005];
int tmp_ans;
void eat_sushi(int a) {
	if (eat[a] == 0) 
		tmp_ans++;
	eat[a] ++;
}
void spit_sushi(int a) {
	eat[a]--;
	if (eat[a] == 0)
		tmp_ans--;
}

int main() {
	int n, d, k, c, ans;
	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++) {
		cin >> sushi[i];
	}
	for (int i = 0; i < k - 1; i++) {
		sushi[i + n] = sushi[i];
	}
   
	eat[c] = 1;
	tmp_ans++;

	for (int i = 0; i < k ; i++) {
		eat_sushi(sushi[i]);
	}
	ans = tmp_ans;

	for (int i = 0; i < n-1 ; i++) {
		spit_sushi(sushi[i]);
		eat_sushi(sushi[i + k]);
		ans = max(ans, tmp_ans);
	}
	

	cout << ans << endl;
}