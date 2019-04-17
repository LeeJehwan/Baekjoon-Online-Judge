#include <iostream>
using namespace std;
#define endl '\n'


struct NODE {
	int prev;
	int next;
	char val;
};

const int NODE_SIZE = 1000000;
NODE node[NODE_SIZE + 2];

struct List {
	const int HEAD = NODE_SIZE;
	const int TAIL = NODE_SIZE + 1;
	int pos;
	int cursor;

	List() {
		cursor = TAIL;
		pos = 0;
		node[HEAD].next = TAIL;
		node[TAIL].prev = HEAD;
	}

	void left() {
		int _left = node[cursor].prev;
		if(_left == HEAD)
			return;
		cursor = _left;
	}

	void right() {
		if (cursor == TAIL)
			return;
		cursor = node[cursor].next;
	}

	void push(char data) {
		int prev = node[cursor].prev;
		int next = node[prev].next;

		node[pos].val = data;
		
		node[pos].prev = prev;
		node[prev].next = pos;

		node[pos].next = next;
		node[next].prev = pos;

		cursor = node[pos].next;
		++pos;
	}

	void erase() {
		if (cursor == HEAD)
			return;
		int target = node[cursor].prev;
		if (target == HEAD)
			return;
		
		int prev = node[target].prev;
		int next = node[target].next;

		node[prev].next = next;
		node[next].prev = prev;

		cursor = next;
	}

	void print() {
		int target = node[HEAD].next;
		while (target != TAIL) {
			cout << node[target].val;
			target = node[target].next;
		}
		cout << endl;
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		List list;
		char str[1000005];
		cin >> str;
		int i = 0;
		while (str[i] != '\0') {
			switch (str[i]){
			case '<': {
				list.left();
				break;
			}
			case '>': {
				list.right();
				break;
			}
				
			case '-':{
				list.erase();
				break;
			}
			default: {
				list.push(str[i]);
				break;
			}
			}
			++i;
		}
		list.print();
	}
}