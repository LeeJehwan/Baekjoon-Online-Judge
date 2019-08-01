#include <iostream>
#include <vector>
using namespace std;
bool virarr[105];
vector <int> v[105];

void virus(int s) {
	if (virarr[s])
		return;
	for (int i = 0; i < v[s].size(); i++) {
		virarr[s] = true;
		virus(v[s][i]);
	}
}


int main() {
	int vertex, edge;
	cin >> vertex >> edge;

	for (int i = 0; i < edge; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		v[temp1].push_back(temp2);
		v[temp2].push_back(temp1);
	}

	virus(1);
	int sum = 0;
	for (int i = 0; i <= vertex; i++)
		sum += virarr[i];
	cout << sum-1 << endl;
	
}