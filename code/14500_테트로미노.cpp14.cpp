#include <iostream>
using namespace std;

int arr[501][501];
int ans = 0;
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	//ㅡㅡㅡㅡ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 3; j++) {
			int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
			if (sum > ans)
				ans = sum;
		}
	}
	/*
	ㅣ
	ㅣ
	ㅣ
	ㅣ
	*/
	for (int i = 0; i < n-3; i++) {
		for (int j = 0; j < m; j++) {
			int sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
			if (sum > ans)
				ans = sum;
		}
	}
	/* ㅁㅁ
	   ㅁㅁ
	*/
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			int sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
			if (sum > ans)
				ans = sum;
		}
	}
	/*1
	ㅁ
	ㅁ
	ㅁㅁ
	*/
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m-1; j++) {
			int sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
			if (sum > ans)
				ans = sum;
		}
	}
	/*2
	ㅁㅁ
	ㅁ
	ㅁ
	*/

	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < m-1; j++) {
			int sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 2][j];
			if (sum > ans)
				ans = sum;
		}
	}
	/*3
	    ㅁ
	ㅁㅁㅁ
	*/
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m-2; j++) {
			int sum = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2] + arr[i][j + 2];
			if (sum > ans)
				ans = sum;
		}
	}

	/*4
	ㅁ
	ㅁㅁㅁ
	*/
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m-2; j++) {
			int sum = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			if (sum > ans)
				ans = sum;
		}
	}
	/*5
	ㅁㅁㅁ
	ㅁ
	*/

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m-2; j++) {
			int sum = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i][j + 2];
			if (sum > ans)
				ans = sum;
		}
	}
	/*6
	ㅁㅁㅁ
	    ㅁ
	*/
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m-2; j++) {
			int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2]; 
			if (sum > ans)
				ans = sum;
		}
	}
	/*7
	ㅁㅁ
	  ㅁ
	  ㅁ	
	*/
	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			if (sum > ans)
				ans = sum;
		}
	}
	/*8
	  ㅁ
	  ㅁ
	ㅁㅁ
	*/
	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < m-1; j++) {
			int sum = arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1] + arr[i + 2][j];
			if (sum > ans)
				ans = sum;
		}
	}
	/*
	ㅁ
	ㅁㅁ
	  ㅁ
	*/
	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < m-1; j++) {
			int sum = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			if (sum > ans)
				ans = sum;
		}
	}
	/*
	  ㅁ
	ㅁㅁ
	ㅁ
	*/
	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int sum = arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j];
			if (sum > ans)
				ans = sum;
		}
	}
	/*
	  ㅁㅁ
	ㅁㅁ
	*/
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m-2; j++) {
			int sum = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i][j + 2];
			if (sum > ans)
				ans = sum;
		}
	}
	/*
	ㅁㅁ
	  ㅁㅁ
	*/
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m-2; j++) {
			int sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			if (sum > ans)
				ans = sum;
		}
	}
	/*
	ㅁㅁㅁ
	  ㅁ
	*/
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
			if (sum > ans)
				ans = sum;
		}
	}
	/*
	  ㅁ
	ㅁㅁ
	  ㅁ
	*/
	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < m-1; j++) {
			int sum = arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			if (sum > ans)
				ans = sum;
		}
	}
	/*
	  ㅁ
	ㅁㅁㅁ
	*/
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m-2; j++) {
			int sum = arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			if (sum > ans)
				ans = sum;
		}
	}
	/*
	ㅁ
	ㅁㅁ
	ㅁ
	*/

	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < m-1; j++) {
			int sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
			if (sum > ans)
				ans = sum;
		}
	}


	cout << ans << '\n';
}

