#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

string bit(int num, string str) {
	if (num == 0) {
		if (str == "")
			return "000";
		string tmp = "";
		int len = str.size();
		int t = 3 - len;
		for (int i = 0; i < t; i++) {
			str.push_back('0');
		}
		for (int i = 0; i < 3; i++) {
			tmp += str.back();
			str.pop_back();
		}
		str = tmp;
		return str;
	}
	str += to_string(num % 2);
	return bit(num / 2, str);
}

string bit2(int num, string str) {
	if (num == 0) {
		if (str == "")
			return "0000";
		string tmp = "";
		int len = str.size();
		int t = 4 - len;
		for (int i = 0; i < t; i++) {
			str.push_back('0');
		}
		for (int i = 0; i < 4; i++) {
			tmp += str.back();
			str.pop_back();
		}
		str = tmp;
		return str;
	}
	str += to_string(num % 2);
	return bit2(num / 2, str);
}


void solve() {
	string str;
	int a, b, c;
	cin >> str >> a >> b >> c;
	string ans = "";

	if (str == "ADD" || str == "ADDC") {
		ans += "0000";
		if (str == "ADD") {
			ans += "00";
			ans += bit(a,"");
			ans += bit(b,"");
			ans += bit(c,"");
			ans += "0";
		}
		else {
			ans += "10";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit2(c, "");
		}
	}
	else if (str == "SUB" || str == "SUBC") {
		ans += "0001";
		if (str == "SUB") {
			ans += "00";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit(c, "");
			ans += "0";
		}
		else {
			ans += "10";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit2(c, "");
		}
	}
	else if (str == "MOV" || str == "MOVC") {
		ans += "0010";
		if (str == "MOV") {
			ans += "00";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit(c, "");
			ans += "0";
		}
		else {
			ans += "10";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit2(c, "");
		}
	}
	else if (str == "AND" || str == "ANDC") {
		ans += "0011";
		if (str == "AND") {
			ans += "00";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit(c, "");
			ans += "0";
		}
		else {
			ans += "10";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit2(c, "");
		}
	}
	else if (str == "OR" || str == "ORC") {
		ans += "0100";
		if (str == "OR") {
			ans += "00";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit(c, "");
			ans += "0";
		}
		else {
			ans += "10";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit2(c, "");
		}
	}
	else if (str == "NOT") {
		ans += "010100";
		ans += bit(a, "");
		ans += bit(b, "");
		ans += bit(c, "");
		ans += "0";
	}
	else if (str == "MULT" || str == "MULTC") {
		ans += "0110";
		if (str == "MULT") {
			ans += "00";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit(c, "");
			ans += "0";
		}
		else {
			ans += "10";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit2(c, "");
		}
	}
	else if (str == "LSFTL" || str == "LSFTLC") {
		ans += "0111";
		if (str == "LSFTL") {
			ans += "00";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit(c, "");
			ans += "0";
		}
		else {
			ans += "10";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit2(c, "");
		}
	}
	else if (str == "LSFTR" || str == "LSFTRC") {
		ans += "1000";
		if (str == "LSFTR") {
			ans += "00";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit(c, "");
			ans += "0";
		}
		else {
			ans += "10";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit2(c, "");
		}
	}
	else if (str == "ASFTR" || str == "ASFTRC") {
		ans += "1001";
		if (str == "ASFTR") {
			ans += "00";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit(c, "");
			ans += "0";
		}
		else {
			ans += "10";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit2(c, "");
		}
	}
	else if (str == "RL" || str == "RLC") {
		ans += "1010";
		if (str == "RL") {
			ans += "00";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit(c, "");
			ans += "0";
		}
		else {
			ans += "10";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit2(c, "");
		}
	}
	else if (str == "RR" || str == "RRC") {
		ans += "1011";
		if (str == "RR") {
			ans += "00";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit(c, "");
			ans += "0";
		}
		else {
			ans += "10";
			ans += bit(a, "");
			ans += bit(b, "");
			ans += bit2(c, "");
		}
	}

	cout << ans << endl;
}




int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}