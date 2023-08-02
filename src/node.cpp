#include "../include/node.h"

node::node(char c, int nV, node *n, node *l, node* r) {
	Character = c;
	nodeValue = nV;
	next = n;
	left = l;
	right = r;
}
