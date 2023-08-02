#include "../include/HuffmanTreeGenerator.h"

HuffmanTreeGenerator::HuffmanTreeGenerator() {
    head = tail = root = NULL;
}

void HuffmanTreeGenerator::add_to_tail(char Character, int nodeValue) {
    if(head == NULL)
        head = tail = new node(Character,nodeValue);
    else
    {
        tail->next = new node(Character,nodeValue);
        tail = tail->next;
    }
}

void HuffmanTreeGenerator::Display() {
    node *tem = head;
    while(tem)
    {
        cout<<tem->Character<<" "<<tem->nodeValue;
        tem = tem->next;
    }
    cout<<endl;
}

void HuffmanTreeGenerator::count_to_linkedList(string Characters, int frequencies[]) {
    for(int i = 0 ; i<Characters.length() ; i++)
    {
        this->add_to_tail(Characters[i],frequencies[Characters[i]]);
    }
}

void HuffmanTreeGenerator::Built_Huffman_Tree() {
    while(head->next)//goign forward till next of head is not NULL
    {
        if(head->next == NULL)
            return;
        int NewNodeValue = (head->nodeValue)+(head->next->nodeValue);
        node *tem = head;
        while(tem->next)//going forward till next of tem is not NULL
        {
            if(tem->next->nodeValue <= NewNodeValue)
                tem = tem->next;//going forward till we appropriate place to insert New node value
            else
                break;//if we have found appropriate place
        }
        if(tem->next == NULL)
        {
            this->add_to_tail(0,NewNodeValue);//inserting new node at the end
            tem = tem->next;
        }
        else
        {
            tem->next = new node(0,NewNodeValue,tem->next);//inserting at appropriate pace
            tem = tem->next;
        }
            
        tem->left = head;//adding the head node to the left of newNodeValue inserted node
        head = head->next;
        tem->left->next = NULL;
        
        tem->right = head;//adding the head node to the right of newNodeValue inserted node
        head = head->next;
        tem->right->next = NULL;	
    }
    root = head;
}

void HuffmanTreeGenerator::Codes(string *Coodes) {
    string codde;
    codes(root,codde, Coodes);
}

void HuffmanTreeGenerator::codeSeach(string temIn, string *temOut, int edgeCount) {
    node *tem = root;
    string temp;
    for(int i = 0 ; i<= temIn.length();i++)
    {
        if(i == (temIn.length()-8) && edgeCount)
                i += (8 - edgeCount);
    
        if(tem->left == NULL && tem->right == NULL)
        {
            temp += tem->Character;
            tem = root;
            
                i--;
        }
        else if(temIn[i] == '0')
            tem = tem->left;
        else if(temIn[i] == '1')
            tem = tem->right;
        
    }
    *temOut = temp;
}

void HuffmanTreeGenerator::codes(node *tem,string codde,string *Coodes)
{
    if(tem->left == NULL && tem->right == NULL)
    {
        Coodes[tem->Character] = codde;//saving codes of character at proper indes e.g A will be saved at 65
        return;
    }
    
    codes(tem->left,codde+'0',Coodes);
    
    codes(tem->right,codde+'1',Coodes);
}