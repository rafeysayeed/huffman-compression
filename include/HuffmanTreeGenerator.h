#ifndef HUFFMANTREEGENERATOR_H
#define HUFFMANTREEGENERATOR_H

#include "node.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <bitset>
#include <cstring>
using namespace std;

class HuffmanTreeGenerator {
	private:
		node *head, *tail, *root;
	public:
		HuffmanTreeGenerator();
		void add_to_tail(char Character = 0, int nodeValue = 0);
		void Display();
		void count_to_linkedList(string Characters, int frequencies[]);
		void Built_Huffman_Tree();
		void Codes(string *Coodes);
		void codeSeach(string temIn,string *temOut,int edgeCount);		
		void codes(node *tem,string codde,string *Coodes);
};

#endif