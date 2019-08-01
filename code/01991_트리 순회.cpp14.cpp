#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'

vector<char> v[26];
void preorder(int n) {
	char tmp = n + 'A';
	cout << tmp;
	if (v[n][0] != '.')
		preorder(v[n][0] - 'A');
	if (v[n][1] != '.')
		preorder(v[n][1] - 'A');
}

void inorder(int n) {
	if (v[n][0] != '.')
		inorder(v[n][0] - 'A');
	char tmp = n + 'A';
	cout << tmp;
	if (v[n][1] != '.')
		inorder(v[n][1] - 'A');
}

void postorder(int n) {
	if (v[n][0] != '.')
		postorder(v[n][0] - 'A');
	if (v[n][1] != '.')
		postorder(v[n][1] - 'A');
	char tmp = n + 'A';
	cout << tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char node, left, right;
		cin >> node >> left >> right;
		v[node - 'A'].push_back(left);
		v[node - 'A'].push_back(right);
	}

	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
	cout << endl;
}