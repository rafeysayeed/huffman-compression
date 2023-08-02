#ifndef DECODER_H
#define DECODER_H

#include "HuffmanTreeGenerator.h"

class Decoder{
	private:
	int frequencies[256];
		int edgeCount;
		long long totalChar;
		string sorted;
	public:	
		Decoder();
		void SortedKeyInput();
		void InputFromCompressed();
};

#endif