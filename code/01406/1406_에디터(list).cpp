#include <iostream>
using namespace std;


struct NODE {
	int prev;
	int next;
	char val;
};

const int NODE_SIZE = 600000;
NODE node[NODE_SIZE + 2];

struct List {
	const int HEAD = NODE_SIZE;
	const int TAIL = NODE_SIZE + 1;
	int pos;
	int cursor;
	int size;

	List() {
		size = 0;
		cursor = HEAD;
		pos = 0;
		node[HEAD].next = TAIL;
		node[TAIL].prev = HEAD;
	}

	void push_back(int data) {
		int prev = node[TAIL].prev;
		int next = node[prev].next;

		node[pos].val = data;
		
		node[pos].prev = prev;
		node[prev].next = pos;

		node[pos].next = next;
		node[next].prev = pos;

		cursor = node[pos].next;
		++pos;
		++size;
	}

	void insert(int data) {
		int prev = node[cursor].prev;
		int next = node[prev].next;

		node[pos].val = data;

		node[pos].prev = prev;
		node[prev].next = pos;

		node[pos].next = next;
		node[next].prev = pos;

		cursor = node[pos].next;
		++pos;
		++size;
	}
	void erase() {
		int target = node[cursor].prev;
		if (target == HEAD)
			return;
		int next = node[target].next;
		int prev = node[target].prev;

		node[prev].next = next;
		node[next].prev = prev;

		--size;
		cursor = next;
	}
	void left() {
		int _left = node[cursor].prev;
		if (_left == HEAD)
			return;
		cursor = _left;
	}
	void right() {
		if (cursor == TAIL)
			return;
		cursor = node[cursor].next;
	}
	void print() {
		int target = node[HEAD].next;
		while (target != TAIL) {
			cout << node[target].val;
			target = node[target].next;
		}
		cout << '\n';
	}
};


int main() {
	char str[100001];
	cin >> str;
	
	List list;
	int i = 0;
	while (str[i] != '\0') {
		list.push_back(str[i]);
		++i;
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		if (ch == 'L') {
			list.left();
		}
		else if (ch == 'D') {
			list.right();
		}
		else if (ch == 'B') {
			list.erase();
		}
		else if (ch == 'P') {
			char c;
			cin >> c;
			list.insert(c);
		}
	}
	list.print();
}