#include "../include/Encoder.h"
#include "../include/Decoder.h"

int main()
{
	char tem;
	cout<<"Do you want to compress or decompress? c/d"<<endl;
	cin>>tem;
	
	if(tem == 'c' || tem == 'C')
	{
		Encoder obj1;
		obj1.InputFromFile();
	}
	else if(tem == 'd' || tem == 'D')
	{
		Decoder obj;
		obj.SortedKeyInput();
	}
}