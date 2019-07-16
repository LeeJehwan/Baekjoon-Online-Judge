#include <iostream>
#include <queue>
using namespace std;

int a[100005];
int main() {
	int k, n;
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}

	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < k; i++)
		pq.push(a[i]);


	for (int i = 0; i < n - 1; i++) {
		long long t = pq.top();
		pq.pop();
		for (int j = 0; j < k; j++) {
			pq.push(a[j] * t);
			if (t % a[j] == 0) break;
		}
	}

	cout << pq.top() << endl;
}