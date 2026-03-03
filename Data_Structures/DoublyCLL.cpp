///////////////////////////////////////////////////////////////
// Final code of Doubly Linear Linked List using Generic approach
///////////////////////////////////////////////////////////////

# include <iostream>
using namespace std;

# pragma pack(1)

template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

        DoublyCLLnode(T No)
        {
            this -> data = No;
            this -> next = NULL;
            this -> prev = NULL;
        }
};

template <class T>
class DoublyCLL
{
    public:
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

        DoublyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template <class T>
DoublyCLL<T> :: DoublyCLL()
{
    this -> first = NULL;
    this -> last = NULL;
    this -> iCount = 0; 
}

template <class T>
void DoublyCLL<T> :: InsertFirst(T No)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(No);

    if(this -> first == NULL && this -> last == NULL)
    {
        this -> first = newn;
        this -> last = newn;
    }
    else
    {
        newn -> next = this -> first;
        this -> first -> prev = newn;
        this -> first = newn;
    }
    this -> last -> next = this -> first;
    this -> first -> prev = this -> last;
    this -> iCount++;
}

template <class T>
void DoublyCLL<T> :: InsertLast(T No)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(No);

    if(this -> first == NULL && this -> last == NULL)
    {
        this -> first = newn;
        this -> last = newn;
    }
    else
    {
        this -> last -> next = newn;
        newn -> prev = this -> last;
        this -> last = newn;
    }
    this -> last -> next = this -> first;
    this -> first -> prev = this -> last;
    this -> iCount++;
}

template <class T>
void DoublyCLL<T> :: InsertAtPos(T No, int pos)
{
    if(pos < 1 || pos > this -> iCount + 1)
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this -> InsertFirst(No);
    }
    else if(pos == this -> iCount + 1)
    {
        this -> InsertLast(No);
    }
    else
    {
        DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(No);
        DoublyCLLnode<T> *temp = NULL;

        int iCnt = 0;

        temp = this -> first;
        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        newn -> next -> prev = newn;
        newn -> prev = temp;
        temp -> next = newn;

        this -> iCount++;
    }
}

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
    DoublyCLLnode<T> *temp = NULL;
    
    if(this -> first == NULL && this -> last == NULL)
    {
        return;
    }
    else if(this -> first == this -> last)
    {
        delete first;
        this -> first = NULL;
        this -> last = NULL;
    }
    else
    {
        this -> first = this -> first -> next;
        delete last -> next;
    }
    this -> last -> next = this -> first;
    this -> first -> prev = this -> last;

    this -> iCount--;
}

template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(this -> first == NULL && this -> last == NULL)
    {
        return;
    }
    else if(this -> first == this -> last)
    {
        delete first;
        this -> first = NULL;
        this -> last = NULL;
    }
    else
    {
        this -> last = this -> last -> prev;
        delete this -> last -> next;
    }
    this -> last -> next = this -> first;
    this -> first -> prev = this -> last;

    this -> iCount--;
}

template <class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    if(pos < 1 || pos > this -> iCount)
    {
        cout << "Invalid Position\n";
        return;
    }

    if(this -> first == NULL && this -> last == NULL)
    {
        this -> DeleteFirst();
    }
    else if(this -> first == this -> last)
    {
        this -> DeleteLast();
    }
    else
    {
        DoublyCLLnode<T> *temp = NULL;
        DoublyCLLnode<T> *target = NULL;

        temp = this -> first;
        int iCnt = 0;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp -> next = target -> next;
        temp -> next -> prev = temp;
        delete target;

        this -> iCount--;
    }
}

template <class T>
void DoublyCLL<T> :: Display()
{
    DoublyCLLnode<T> *temp = NULL;

    temp = first;

    cout << "\n<=> ";
    do
    {
        cout << "| " << temp -> data << " | <=> ";
        temp = temp -> next;
    }while(temp != first);
    cout << "\n";
}

template <class T>
int DoublyCLL<T> :: Count()
{
    return this -> iCount;
}

int main()
{
    DoublyCLL<int> *dcobj = new DoublyCLL<int>();

    dcobj -> InsertFirst(51);
    dcobj -> InsertFirst(21);
    dcobj -> InsertFirst(11);

    dcobj -> Display();
    cout << "Number of nodes : " << dcobj -> Count() << "\n";

    dcobj -> InsertLast(101);
    dcobj -> InsertLast(121);
    dcobj -> InsertLast(151);

    dcobj -> Display();
    cout << "Number of nodes : " << dcobj -> Count() << "\n";

    dcobj -> InsertAtPos(111, 5);

    dcobj -> Display();
    cout << "Number of nodes : " << dcobj -> Count() << "\n";

    dcobj -> DeleteFirst();

    dcobj -> Display();
    cout << "Number of nodes : " << dcobj -> Count() << "\n";

    dcobj -> DeleteLast();

    dcobj -> Display();
    cout << "Number of nodes : " << dcobj -> Count() << "\n";

    dcobj -> DeleteAtPos(4);

    dcobj -> Display();
    cout << "Number of nodes : " << dcobj -> Count() << "\n";

    delete dcobj;    

    return 0;
}