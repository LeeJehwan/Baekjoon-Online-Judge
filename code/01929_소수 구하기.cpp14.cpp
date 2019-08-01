#include <iostream>
using namespace std;

int prime[1000001];
bool count_p[1000001];
int cnt = 0;
void eratos() {
	for (int i = 2; i <= 1000000; i++) {
		if (count_p[i] == false)
			prime[cnt++] = i;
		for (int j = i * 2; j <= 1000000; j += i)
			count_p[j] = true;
	}
}

int main() {
	eratos();

	int n, m;
	cin >> n >> m;
	int i = 0;
	while (1) {
		if (m < prime[i])
			break;
		if (n <= prime[i])
			cout << prime[i] << '\n';
		i++;
	}

}