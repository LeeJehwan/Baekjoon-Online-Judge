#include <iostream>
using namespace std;
void print();

int arr[5];
void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
	print();
}

void print() {
	for (auto x : arr)
		cout << x << " ";
	cout << '\n';
}


int main() {
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4 - i; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}

}