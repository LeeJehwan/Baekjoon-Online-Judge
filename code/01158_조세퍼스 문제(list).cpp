#include <iostream>
using namespace std;

struct NODE {
	int prev;
	int next;
	int val;
};

const int NODE_SIZE = 5000;

struct List {
	const int HEAD = NODE_SIZE;
	const int TAIL = NODE_SIZE + 1;
	NODE node[NODE_SIZE + 2];
	int cur = HEAD;
	int pos;
	int size;

	List() {
		size = 0;
		pos = 0;
		node[HEAD].next = TAIL;
		node[TAIL].next = HEAD;
		node[TAIL].prev = HEAD;
		node[HEAD].prev = TAIL;
	}

	void push_back(int data) {
		int prev = node[TAIL].prev;
		int next = node[prev].next;

		node[pos].val = data;
		
		node[pos].prev = prev;
		node[prev].next = pos;

		node[pos].next = next;
		node[next].prev = pos;
		++pos;
		++size;
	}

	int erase(int p) {
		int target = node[cur].next;
		if (target == TAIL) {
			p += 2;
		}
		for (int i = 0; i < p-1; ++i) {
			target = node[target].next;
			if (target == TAIL) {
				p += 2;
			}
		}
		cur = target;

		int next = node[target].next;
		int prev = node[target].prev;

		node[prev].next = next;
		node[next].prev = prev;
		--size;
		return node[target].val;
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	List list;
	for (int i = 1; i <= n; i++) {
		list.push_back(i);
	}

	cout << "<";
	for (int i = 0; i < n - 1; i++) {
		int tmp = m % (list.size);
		if (tmp == 0)
			tmp = list.size;
		cout << list.erase(tmp) << ", ";
	}
	cout << list.erase(m) << ">" << endl;
}