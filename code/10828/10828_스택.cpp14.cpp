#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define endl '\n'

int main() {
	stack<int> st;
	int n;
	cin >> n;

	while (n--) {
		string str;
		cin >> str;

		if (str == "push") {
			int num;
			cin >> num;
			st.push(num);

		}
		else if (str == "pop") {
			if (st.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << st.top() << endl;
				st.pop();
			}
		}
		else if (str == "size") {
			cout << st.size() << endl;
		}
		else if (str == "empty") {
			if (st.empty()) {
				cout << 1 << endl;
			}
			else
				cout << 0 << endl;
		}
		else if (str == "top") {
			if (st.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << st.top() << endl;
			}
		}

		

	}
	

	

}