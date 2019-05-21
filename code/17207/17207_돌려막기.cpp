#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int mat1[5][5];
int mat2[5][5];
int mat3[5][5];
int ans[5];

bool cmp(pair<int, string> v1, pair<int, string> v2) {
	return v1.first < v2.first;
}


int main() {
	string name[5] = { "Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki" };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> mat1[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> mat2[i][j];
		}
	}


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				mat3[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ans[i] += mat3[i][j];
		}
	}

	vector<pair<int, string>> v;
	for (int i = 4; i >= 0; i--) {
		v.push_back({ ans[i], name[i] });
	}

	stable_sort(v.begin(), v.end(), cmp);
	cout << v[0].second << endl;

}