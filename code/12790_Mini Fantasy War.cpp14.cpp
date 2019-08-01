#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int hp, mp, att, def;
		cin >> hp >> mp >> att >> def;
		int hp2, mp2, att2, def2;
		cin >> hp2 >> mp2 >> att2 >> def2;
		hp += hp2;
		mp += mp2;
		att += att2;
		def += def2;
		if (hp < 1)
			hp = 1;
		if (mp < 1)
			mp = 1;
		if (att < 0)
			att = 0;
		int ability = hp + 5 * mp + 2 * att + 2 * def;
		cout << ability << endl;
	}
}