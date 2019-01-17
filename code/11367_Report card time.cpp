#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		int p;
		string g;
		cin >> s >> p;

		if (p >= 97)
			g = "A+";
		else if (p >= 90)
			g = "A";
		else if (p >= 87)
			g = "B+";
		else if (p >= 80)
			g = "B";
		else if (p >= 77)
			g = "C+";
		else if (p >= 70)
			g = "C";
		else if (p >= 67)
			g = "D+";
		else if (p >= 60)
			g = "D";
		else
			g = "F";

		cout << s << " " << g << endl;
	}
}
