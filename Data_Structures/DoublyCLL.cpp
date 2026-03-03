# include <iostream>
using namespace std;

class DoublyCLLnode
{
    public:
        int data;
        DoublyCLLnode *next;
        DoublyCLLnode *prev;

        DoublyCLLnode(int No)
        {
            this -> data = No;
            this -> next = NULL;
            this -> prev = NULL;
        }
};

class DoublyCLL
{
    public:
        DoublyCLLnode *first;
        DoublyCLLnode *last;
        int iCount;

        DoublyCLL()
        {
            this -> first = NULL;
            this -> last = NULL;
            this -> iCount = 0; 
        }

        void InsertFirst(int No)
        {
            
        }
};

int main()
{
    DoublyCLL *dcobj = new DoublyCLL(); 

    return 0;
}