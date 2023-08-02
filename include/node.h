#ifndef NODE_H
#define NODE_H

class node {

	public:
		char Character;
		int nodeValue;
		node *next, *left, *right;
		node(char c = 0, int nV = 0, node *n = nullptr, node *l = nullptr, node* r = nullptr);
};

#endif