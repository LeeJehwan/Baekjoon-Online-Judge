#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int arr[10][10];
	int max = 0;
	int m_i, m_j;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
			if (max < arr[i][j]) {
				max = arr[i][j];
				m_i = i;
				m_j = j;
			}
		}
	}
	cout << max << endl;
	cout << m_i << " " << m_j << endl;
}