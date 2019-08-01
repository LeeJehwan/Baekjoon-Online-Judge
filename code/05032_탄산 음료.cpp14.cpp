#include <iostream> 
using namespace std;

int main() {
	int now, drop, need;
	cin >> now >> drop >> need;
	now += drop;
	int sum = now / need;
	now = now % need;
	now += sum; 
	
	while (1) {
		if (now < need)
			break;

		now -= need;
		sum++;
		now++;

	}
	cout << sum << endl;


}