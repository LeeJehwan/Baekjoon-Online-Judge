#include <iostream>
using namespace std;

long long div5(long long n) {
	long long count = 0;
	for (long long i = 5; i <= n; i *= 5)
		count += n / i;
	return count;
}

long long div2(long long n) {
	long long count = 0;
	for (long long i = 2; i <= n; i *= 2)
		count += n / i;
	return count;
}

int main() {
	long long n, m;
	cin >> n >> m;
	long long k = n - m;
	
	long long n_2, n_5;
	long long m_2, m_5;
	long long k_2, k_5;

	n_2 = div2(n);
	n_5 = div5(n);

	m_2 = div2(m);
	m_5 = div5(m);

	k_2 = div2(k);
	k_5 = div5(k);

	long long sum_2 = n_2 - m_2 - k_2;
	long long sum_5 = n_5 - m_5 - k_5;

	long long ret = sum_2 < sum_5 ? sum_2 : sum_5;
	cout << ret << endl;
}