#ifndef ENCODER_H
#define ENCODER_H

#include "HuffmanTreeGenerator.h"

class Encoder {
	private:
		int frequencies[256];
		string sorted;
		string Coodes[256];
		string fileName;
	public:
		Encoder();
		void InputFromFile();
		void GeneratingTree();
		void WriteToFile();
};

#endif