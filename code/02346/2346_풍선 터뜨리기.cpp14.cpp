#include <iostream>
#include <list>
using namespace std;

int main() {
	int num;
	cin >> num;

	list<pair<int, int>> l;

	for (int i = 1; i <= num; i++) {
		int t;
		cin >> t;
		l.emplace_back(t, i);		//first 값 // second 숫자
	}

	auto it = l.begin();
	for (int i = 0; i < num - 1; i++) {
		int t = it->first;
		cout << it->second << " ";
		if (t > 0) {
			it = l.erase(it);
			if (it == l.end())
				it = l.begin();
			for (int j = 1; j < t; j++) {
				++it;
				if (it == l.end())
					it = l.begin();
			}
		}
		else if (t < 0) {
			t = -t;
			it = l.erase(it);
			if (it == l.end())
				it = l.begin();
			for (int j = 0; j < t; j++) {
				if (it == l.begin())
					it = l.end();
				--it;
				
			}

		}
	}



	cout << it->second << endl;

}