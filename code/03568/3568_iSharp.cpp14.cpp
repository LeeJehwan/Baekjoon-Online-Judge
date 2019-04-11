#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
	string str;
	getline(cin, str);
	
	vector<string> v;
	int len = str.size();
	string tmp = "";
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ' || str[i] == ',' || str[i] == ';') {
			if (tmp.length() != 0)
				v.push_back(tmp);
			tmp = "";
		}
		else
			tmp += str[i];
	}

	for (int i = 1; i < v.size(); i++) {
		string first = v[0];
		while (v[i].length() > 0 && !(v[i].back() >= 'a' && v[i].back() <= 'z')) {
			if (v[i].back() == '[')
				first += ']';
			else if (v[i].back() == ']')
				first += '[';
			else
				first += v[i].back();
			v[i].pop_back();
		}
		cout << first << " " << v[i] << ";" << endl;
	}

}