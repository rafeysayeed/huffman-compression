#include "../include/Decoder.h"

Decoder::Decoder() {
    memset(frequencies,0,sizeof(int)*256);
}

void Decoder::SortedKeyInput() {
    ifstream inSort("SortedKey.txt");
    if(inSort)
    {
        int size;
        char tem;
        
        while(inSort.get(tem))
        {
            sorted +=tem;
        }

        inSort.close();
        ifstream InFrequencies("Frequencies.txt");
        InFrequencies>>edgeCount;
        for(int i= 0 ; i<sorted.length(); i++)
        {
            InFrequencies>>frequencies[sorted[i]];
        }
        InFrequencies.close();
        
        InputFromCompressed();

    }
    
}
void Decoder::InputFromCompressed() {
    HuffmanTreeGenerator obj;
    
    obj.count_to_linkedList(sorted,frequencies);
    obj.Built_Huffman_Tree();
    ifstream inCompress("compressedFile.bin",ios::binary);
    ofstream outCompress("UncompressedFile.txt",ios::binary);
    if(inCompress && outCompress )
    {
        string temIn;
        string temOut;
        char temp;
        int j = 0;
        while(inCompress.get(temp))
        {
            temIn += temp;
        }
            string tem;
            for(int i = 0 ; i<temIn.length();i++)
                tem += bitset<8>(temIn[i]).to_string();
                
        
            obj.codeSeach(tem,&temOut,edgeCount);

            outCompress<<temOut;

        
        inCompress.close();
        outCompress.close();	
    }
}