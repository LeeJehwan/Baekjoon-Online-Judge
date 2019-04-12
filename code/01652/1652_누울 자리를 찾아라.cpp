#include <iostream>
using namespace std;

char map[101][101];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int row = 0;
	int col = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		bool t = true;
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '.' && t) {
				cnt++;
				if (cnt == 2) {
					row++;
					t = false;
				}
			}
			else if(map[i][j] == 'X'){
				cnt = 0;
				t = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		bool t = true;
		for (int j = 0; j < n; j++) {
			if (map[j][i] == '.' && t) {
				cnt++;
				if (cnt == 2) {
					col ++;
					t = false;
				}
			}
			else if(map[j][i] =='X') {
				cnt = 0;
				t = true;
			}
		}
	}
	cout << row << " " << col << endl;
}