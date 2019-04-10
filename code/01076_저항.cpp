#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> reg;

	reg["black"] = 0;
	reg["brown"] = 1;
	reg["red"] = 2;
	reg["orange"] = 3;
	reg["yellow"] = 4;
	reg["green"] = 5;
	reg["blue"] = 6;
	reg["violet"] = 7;
	reg["grey"] = 8;
	reg["white"] = 9;

	string str[3];
	for (int i = 0; i < 3; i++)
		cin >> str[i];

	if (reg[str[0]])
		cout << reg[str[0]];
	cout << reg[str[1]];

	for (int i = 0; i < reg[str[2]]; i++)
		if (reg[str[0]] || reg[str[1]])
			cout << 0;

	cout << endl;
}