#include "../include/Encoder.h"

Encoder::Encoder(){ memset(frequencies,0,sizeof(int)*256);}

void Encoder::InputFromFile() {
    ifstream check("UncompressedFile.txt",ios::binary);
    if(check &&check.peek() == std::ifstream::traits_type::eof())//checking if the file is empty
    {
        cout << "Your file is empty.";
        return;
    }
    check.close();
    ifstream In("UncompressedFile.txt",ios::binary);
    
    if(In)
    {
        
        string tem;
        char temp;
        while(In.get(temp))
        {
            frequencies[temp]++;//increasing the frequencies according to their index e.g a = 97
        }
        for(int i = 0 ; i<256 ; i++)
        {
            if(frequencies[i] != 0)
                sorted += i;//adding the characters to remember their indexes
        }
        for(int i = 0 ; i<sorted.length();i++)//might use a different sort
        {
            for(int j = i; j<sorted.length(); j++)
                if(frequencies[sorted[j]] < frequencies[sorted[i]])
                {
                    swap(sorted[j],sorted[i]);
                }
        }
        In.close();
        
        GeneratingTree();
        
        WriteToFile();
        
    }
    else
        cout<<"Sorry this file does not exist";
}

void Encoder::GeneratingTree()
{
    HuffmanTreeGenerator obj;
    obj.count_to_linkedList(sorted,frequencies);
    obj.Built_Huffman_Tree();
    obj.Codes(Coodes);
}

void Encoder::WriteToFile()
{
    int edgeCount;
    ifstream In("UncompressedFile.txt",ios::binary);
    ofstream Out("compressedFile.bin",ios::binary);
    if(In && Out)
    {
        char temp;
        string tem;
        while(In.get(temp))
        {	
            tem +=Coodes[temp];
        }
            edgeCount = tem.length()%8;
            stringstream sstream(tem);
            string output;

            while(sstream.good())
            {
                bitset<8> bits;
                sstream >> bits;
                char c = char(bits.to_ulong());
                output += c;
            }
            
            Out<<output;

        
        In.close();
        Out.close();
        //remove("UncompressedFile.txt"); for later use
    }
    
    ofstream SortedKey("SortedKey.txt");
    
    if(SortedKey)
    {
        SortedKey<<sorted;
        SortedKey.close();
        ofstream Frequencies("Frequencies.txt");
        Frequencies<<edgeCount<<'\n';
        for(int i = 0 ; i<sorted.length(); i++)
        {
            Frequencies<<frequencies[sorted[i]]<<'\n';
        }
        Frequencies.close();
    }
}