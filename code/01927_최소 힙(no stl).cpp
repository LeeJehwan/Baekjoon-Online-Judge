#include <iostream>
using namespace std;
#define endl '\n'

int heap[100002];
int heap_size;

void push(int data) {
	int target = heap_size + 1;
	while (target != 1 && heap[target / 2] > data) {
		heap[target] = heap[target / 2];
		target /= 2;
	}
	heap[target] = data;
	++heap_size;
}

void pop() {
	int parent = 1, child = 2;
	int temp = heap[heap_size];
	while (heap_size > child) {
		if (child + 1 < heap_size && heap[child] > heap[child + 1]) {
			child++;
		}
		if (temp <= heap[child])
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	--heap_size;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	while (n--) {
		int cmd;
		cin >> cmd;
		if (cmd == 0) {
			if (heap_size == 0) {
				cout << 0 << endl;
			}
			else {
				cout << heap[1] << endl;
				pop();
			}
		}
		else {
			push(cmd);
		}
	}
}


