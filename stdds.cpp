/////////////////////////////////////////////////////////////////////////////
//              Generalized Data Structure
////////////////////////////////////////////////////////////////////////////

/*
--------------------------------------------------------------------------------------------
    Type                    Name of class for node              Name of class for Functionality
--------------------------------------------------------------------------------------------
    Singly Linear               SinglyLLLnode                       SinglyLLL       Done
    Singly Circular             SinglyCLLnode                       SinglyCLL       Done
    Doubly Linear               DoublyLLLnode                       DoublyLLL       Done
    Doubly Circular             DoublyCLLnode                       DoublyCLL
    Stack                       Stacknode                           Stack           Done
    Queue                       Queuenode                           Queue           Done
    BST                             -                               
    Sorting                         -
    Searching                       -
*/

#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////
//          Singly Linear Linked List using Generic Approach
/////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T No)
        {
            this -> data = No;
            this -> next = NULL;
        }    
};

template<class T>
class SinglyLLL
{
    private:
        SinglyLLLnode<T> *first;
        int iCount;
    
    public:
        SinglyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout << "Object of SinglyLL gets created.\n";
    this -> first = NULL;
    this -> iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      InsertFirst
// Input :              Data of node
// Output :             Nothing
// Description :        Used to insert node at first position
// Author :             Umesh Shivaji Bhabad
// Date :               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T No)
{
    SinglyLLLnode<T> *newn = NULL;

    newn = new SinglyLLLnode<T>(No);

    newn -> next = this -> first;
    this -> first = newn;

    this -> iCount++;
}

template<class T>
void SinglyLLL<T> :: InsertLast(T No)    
{
    SinglyLLLnode<T> *newn = NULL;
    SinglyLLLnode<T> *temp = NULL;

    newn = new SinglyLLLnode<T>(No);

    if(this -> iCount == 0)     // Updated
    {
        this -> first = newn;
    }
    else
    {
        temp = this -> first;

        while(temp -> next != NULL) // type 2
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }

    this -> iCount++;
}

template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> *temp = NULL;

    if(this -> first == NULL)
    {
        return;
    }
    else if((this -> first) -> next == NULL)  // this -> iCount == 1
    {
        delete(this -> first);
        this -> first = NULL;
    }
    else
    {
        temp = this -> first;

        (this -> first) = (this -> first) -> next;
        delete temp;
    }

    this -> iCount--;
}

template<class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> *temp = NULL;

    if(this -> first == NULL)
    {
        return;
    }
    else if(this -> first -> next == NULL)  // this -> iCount == 1
    {
        delete this -> first;
        this -> first = NULL;
    }
    else
    {
        temp = this -> first;

        while((temp -> next)-> next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;
    }

    this -> iCount--;
}

template<class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T> *temp = NULL;
    int iCnt = 0;
    temp = this -> first;

    for(iCnt = 1; iCnt <= this -> iCount; iCnt++)   // Updated : Using for loop
    {
        cout << "| "<< temp -> data <<"| ->";
        temp = temp -> next;
    }
    cout<< "NULL"<< "\n";
}

template<class T>
int SinglyLLL<T> :: Count()
{
    return (this -> iCount);
}

template<class T>
void SinglyLLL<T> :: InsertAtPos(T No, int pos)
{
    SinglyLLLnode<T> *temp = NULL;
    SinglyLLLnode<T> *newn = NULL;

    int iCnt = 0;
    
    if(pos < 1 || pos > (this -> iCount) + 1)
    {
        cout << "Invalid Position" << "\n";
        return;
    }

    if(pos == 1)
    {
        this -> InsertFirst(No);
    }
    else if(pos == (this -> iCount) + 1)
    {
        this -> InsertLast(No);
    }
    else
    {            
        newn = new SinglyLLLnode<T>(No);

        temp = this -> first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;

        this -> iCount++;
    }
}

template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T> *temp = NULL;
    SinglyLLLnode<T> *target = NULL;

    int iCnt = 0;
    
    if(pos < 1 || pos > (this -> iCount))
    {
        cout << "Invalid Position" << "\n";
        return;
    }

    if(pos == 1)
    {
        this -> DeleteFirst();
    }
    else if(pos == (this -> iCount))
    {
        this -> DeleteLast();
    }
    else
    {
        temp = this -> first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        
        target = temp -> next;

        temp -> next = target -> next;

        delete target;

        this -> iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////
//          Singly Circular Linked List using Generic Approach
/////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
class SinglyCLLLnode
{
    public:
        T data;
        SinglyCLLLnode<T> *next;

        SinglyCLLLnode(T No)
        {
            this -> data = No;
            this -> next = NULL;
        }
};

template <class T>
class SinglyCLLL
{
    public:
        SinglyCLLLnode<T> *first;
        SinglyCLLLnode<T> *last;
        int iCount;

    public:
        SinglyCLLL();

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
SinglyCLLL<T> :: SinglyCLLL()
{
    this -> first = NULL;
    this -> last = NULL;
    this -> iCount = 0;
}

template <class T>
void SinglyCLLL<T> :: InsertFirst(T No)
{
    SinglyCLLLnode<T> *newn = NULL;

    newn = new SinglyCLLLnode<T>(No);

    if(this -> first == NULL && this -> last == NULL)
    {
        this -> first = newn;
        this -> last = newn;
    }
    else
    {
        newn -> next = this -> first;
        this -> first = newn;
    }
    this -> last -> next = first;
    this -> iCount++;
}

template <class T>
void SinglyCLLL<T> :: InsertLast(T No)
{
    SinglyCLLLnode<T> *newn = NULL;

    newn = new SinglyCLLLnode<T>(No);

    if(this -> first == NULL && this -> last == NULL)
    {
        this -> first = newn;
        this -> last = newn;
    }
    else
    {
        this -> last -> next = newn;
        this -> last = newn;
    }
    this -> last -> next = this -> first;
    this -> iCount++;
}

template <class T>
void SinglyCLLL<T> :: InsertAtPos(T No, int pos)
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
        SinglyCLLLnode<T> *newn = new SinglyCLLLnode<T>(No);

        SinglyCLLLnode<T> *temp = NULL;

        temp = first;

        for(int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;
    }
    this -> iCount++;
}

template <class T>
void SinglyCLLL<T> :: DeleteFirst()
{
    SinglyCLLLnode<T> *temp = NULL;

    if(this -> first == NULL && this -> last == NULL)
    {
        return;
    }
    else if(this -> first == this -> last)
    {
        delete this -> first;
        this -> first = NULL;
        this -> last = NULL;
    }
    else
    {
        temp = this -> first;
        this -> first = this -> first -> next;
        delete temp;
    }
    this -> last -> next = first;
    this -> iCount--;
}

template <class T>
void SinglyCLLL<T> :: DeleteLast()
{
    SinglyCLLLnode<T> *temp = NULL;

    if(this -> first == NULL && this -> last == NULL)
    {
        return;
    }
    else if(this -> first == this -> last)
    {
        delete this -> first;
        this -> first = NULL;
        this -> last = NULL;
    }
    else
    {
        temp = this -> first;

        while(temp -> next -> next != this -> first)
        {
            temp = temp -> next;
        }

        this -> last = temp;
        delete this -> last -> next;
    }
    this -> last -> next = this -> first;
    this -> iCount--;
}

template <class T>
void SinglyCLLL<T> :: DeleteAtPos(int pos)
{
    if(pos < 1 || pos > this -> iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this -> DeleteFirst();
    }
    else if(pos == this -> iCount)
    {
        this -> DeleteLast();
    }
    else
    {
        int iCnt = 0;
        SinglyCLLLnode<T> *temp = NULL;
        SinglyCLLLnode<T> *target = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = target -> next;
        delete target;
    }
    this -> iCount--;
}

template <class T>
void SinglyCLLL<T> :: Display()
{
    SinglyCLLLnode<T> *temp = NULL;

    temp = first;
    
    do
    {
        cout << "| " << temp -> data << " | --> ";
        temp = temp -> next;
    }while(temp != this -> first);
    
    cout << "\n";
}

template <class T>
int SinglyCLLL<T> :: Count()
{
    return this -> iCount;
}

/////////////////////////////////////////////////////////////////////////
//          Doubly Linear Linked List using Generic Approach
/////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T No)
        {
            this -> data = No;
            this -> next = NULL;
            this -> prev = NULL;
        }
};

template <class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> *first;
        int iCount;
    
    public:
        DoublyLLL();

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
DoublyLLL <T> :: DoublyLLL()
{
    cout << "Linked List gets created\n";
    
    this -> first = NULL;
    this -> iCount = 0;
}

template <class T>
void DoublyLLL <T> :: InsertFirst(T No)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(No);

    if(this -> first == NULL)
    {
        this -> first = newn;
    }
    else
    {
        newn -> next = this -> first;
        this -> first -> prev = newn;
        this -> first = newn;
    }

    this -> iCount++;
}

template <class T>
void DoublyLLL <T> :: InsertLast(T No)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(No);

    if(this -> first == NULL)
    {
        this -> first = newn;
    }
    else
    {
        temp = this -> first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
        newn -> prev = temp;
    }

    this -> iCount++;
}

template <class T>
void DoublyLLL <T> :: InsertAtPos(T No, int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this -> iCount + 1))
    {
        cout << "Invalid Position.\n";
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
        newn = new DoublyLLLnode<T>(No);

        temp = this -> first;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        newn -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;

        this -> iCount++;
    }
}

template <class T>
void DoublyLLL <T> :: DeleteFirst()
{
    if(this -> first == NULL)   // LL is empty
    {
        return;
    }
    else if (this -> first -> next == NULL)     // LL contains one node
    {
        delete this -> first;
        first = NULL;
    }
    else    // LL contains more than 1 node
    {
        this -> first = this -> first -> next;
        
        delete this -> first -> prev;
        this -> first -> prev = NULL;
    }
    this -> iCount--;
}

template <class T>
void DoublyLLL <T> :: DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this -> first == NULL)   // LL is empty
    {
        return;
    }
    else if (this -> first -> next == NULL)     // LL contains one node
    {
        delete this -> first;
        first = NULL;
    }
    else    // LL contains more than 1 node
    {
        temp = this -> first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;
    }
    this -> iCount--;
}

template <class T>
void DoublyLLL <T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this -> iCount))
    {
        cout << "Invalid Position.\n";
        return;
    }

    if(pos == 1)
    {
        this -> DeleteFirst();
    }
    else if(pos == this -> iCount)
    {
        this -> DeleteLast();
    }
    else
    {
        temp = this -> first;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;

        this -> iCount--;
    }
}

template <class T>
void DoublyLLL <T> :: Display()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this -> first;

    cout<< "\nNULL <=>";
    while(temp != NULL)
    {
        cout << "|" << temp -> data<< "| <=> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}

template <class T>
int DoublyLLL <T> :: Count()
{
    return this -> iCount;
}

/////////////////////////////////////////////////////////////////////////
//          Doubly Circular Linked List using Generic Approach
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
//          Stack using Generic Approach
/////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;

        Stacknode(T No)
        {
            this -> data = No;
            this -> next = NULL;
        }
};

template<class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();
        void push(T);
        T pop();
        T peep();
        void Display();
        int Count();
};

template<class T>
Stack<T> :: Stack()
{
    cout << "Stack gets created Sucessfully.\n";
    this -> first = NULL;
    this -> iCount = 0;
}

template<class T>
void Stack<T> :: push(T No)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(No);

    newn -> next = this -> first;
    this -> first = newn;

    this -> iCount++;
}

template<class T>
T Stack<T> :: pop()
{
    T Value = 0;

    Stacknode<T> * temp = this -> first;

    if(this -> first == NULL)
    {
        cout << "Stack is empty.\n";
        return -1;
    }
    
    Value = this -> first -> data;
    
    this -> first = this -> first -> next;

    delete temp;

    this -> iCount--;

    return Value;
}

template<class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this -> first == NULL)
    {
        cout << "Stack is empty.\n";
        return -1;
    }
    
    Value = this -> first -> data;

    return Value;
}

template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = NULL;
    temp = this -> first;

    if(this -> first == NULL)
    {
        cout<< "Stack is empty.\n";
        return;
    }

    while(temp != NULL)
    {
        cout << "|\t" << temp -> data << "\t|\n";
        temp = temp -> next; 
    }
}

template<class T>
int Stack<T> :: Count()
{
    return this -> iCount;
}

/////////////////////////////////////////////////////////////////////////
//          Queue using Generic Approach
/////////////////////////////////////////////////////////////////////////


#pragma pack(1)

template<class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> *next;

        Queuenode(T No)
        {
            this -> data = No;
            this -> next = NULL;
        }
};

template<class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;

    public:
        Queue();
        void enqueue(T);
        T dequeue();
        void Display();
        int Count();
};

template<class T>
Queue<T> :: Queue()
{
    cout << "Queue gets created Sucessfully.\n";

    this -> first = NULL;
    this -> last = NULL;
    this -> iCount = 0;
}

template<class T>
void Queue<T> :: enqueue(T No)
{
    Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>(No);

    if(this -> first == NULL && this -> last == NULL)
    {
        this -> first = newn;
        this -> last = newn;
    }
    else
    {
        this -> last -> next = newn;
        this -> last = this -> last -> next;
    }
    this -> iCount++;
}

template<class T>
T Queue<T> :: dequeue()
{
    T Value = 0;

    Queuenode<T> *temp = this -> first;

    if(this -> first == NULL && this -> last == NULL)
    {
        cout << "Queue is empty.\n";
        return -1;
    }else if (first == last)
    {
        Value = this -> first -> data;
        delete this -> first;
        this -> first = NULL;
        this -> last = NULL;
    }
    else
    {
        Value = this -> first -> data;
    
        this -> first = this -> first -> next;

        delete temp;

        this -> iCount--;
    }

    return Value;
}

template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = NULL;
    temp = this -> first;

    if(this -> first == NULL && this -> last == NULL)
    {
        cout<< "Queue is empty.\n";
        return;
    }

    while(temp != NULL)
    {
        cout << "| " << temp -> data << "| - ";
        temp = temp -> next; 
    }
    cout<< "\n";
}

template<class T>
int Queue<T> :: Count()
{
    return this -> iCount;
}

///////////////////////////////// End of Library ///////////////////////////////////////////////////////////

int main()
{
    SinglyLLL<int> *slobj = new SinglyLLL<int>();
    int iRet = 0;

    slobj->InsertFirst(51);
    slobj->InsertFirst(21);
    slobj->InsertFirst(11);

    slobj->Display();
    iRet = slobj->Count();

    cout << "Number of nodes are : " << iRet << "\n";

    slobj->InsertLast(101);
    slobj->InsertLast(111);
    slobj->InsertLast(121);

    slobj->Display();
    iRet = slobj->Count();

    cout << "Number of nodes are : " << iRet << "\n";

    slobj->DeleteFirst();

    slobj->Display();
    iRet = slobj->Count();

    cout << "Number of nodes are : " << iRet << "\n";

    slobj->DeleteLast();

    slobj->Display();
    iRet = slobj->Count();

    cout << "Number of nodes are : " << iRet << "\n";

    slobj->InsertAtPos(105, 4);

    slobj->Display();
    iRet = slobj->Count();

    cout << "Number of nodes are : " << iRet << "\n";

    slobj->DeleteAtPos(4);

    slobj->Display();
    iRet = slobj->Count();

    cout << "Number of nodes are : " << iRet << "\n";

    delete slobj;

    //////////////////////////////////////////////////////////////////////////////

    SinglyCLLL<int> *scobj = new SinglyCLLL<int>();

    scobj->InsertFirst(51);
    scobj->InsertFirst(21);
    scobj->InsertFirst(11);

    scobj->Display();
    cout << "Number of Nodes in Linked List : " << scobj -> Count() << "\n";

    scobj->InsertLast(101);
    scobj->InsertLast(111);
    scobj->InsertLast(151);

    scobj->Display();
    cout << "Number of Nodes in Linked List : " << scobj -> Count() << "\n";

    scobj->InsertAtPos(121, 3);

    scobj->Display();
    cout << "Number of Nodes in Linked List : " << scobj -> Count() << "\n";

    scobj->DeleteFirst();

    scobj->Display();
    cout << "Number of Nodes in Linked List : " << scobj -> Count() << "\n";

    scobj->DeleteLast();

    scobj->Display();
    cout << "Number of Nodes in Linked List : " << scobj -> Count() << "\n";

    scobj->DeleteAtPos(3);

    scobj->Display();
    cout << "Number of Nodes in Linked List : " << scobj -> Count() << "\n";

    delete scobj;

    //////////////////////////////////////////////////////////////////////////////

    DoublyLLL <char>*dobj = new DoublyLLL<char>();

    dobj -> InsertFirst('A');
    dobj -> InsertFirst('B');
    dobj -> InsertFirst('C');

    dobj -> Display();

    cout<< "Number of elements are : "<< dobj -> Count() << "\n";

    dobj -> InsertLast('X');
    dobj -> InsertLast('Y');
    dobj -> InsertLast('Z');

    dobj -> Display();

    cout<< "Number of elements are : "<< dobj -> Count() << "\n";

    dobj -> DeleteFirst();

    dobj -> Display();

    cout<< "Number of elements are : "<< dobj -> Count() << "\n";

    dobj -> DeleteLast();

    dobj -> Display();

    cout<< "Number of elements are : "<< dobj -> Count() << "\n";

    dobj -> InsertAtPos('$',4);

    dobj -> Display();

    cout<< "Number of elements are : "<< dobj -> Count() << "\n";

    dobj -> DeleteAtPos(4);

    dobj -> Display();

    cout<< "Number of elements are : "<< dobj -> Count() << "\n";

    delete dobj;

    ////////////////////////////////////////////////////////////////////////////

    Stack <char>*sobj = new Stack<char>();

    sobj -> push('A');
    sobj -> push('B');
    sobj -> push('C');
    sobj -> push('D');
    
    sobj -> Display();

    cout << "Number of elements in stack are : "<< sobj -> Count()<< "\n";

    cout << "Return value of peep is "<< sobj -> peep()<< "\n";

    sobj -> Display();

    cout << "Number of elements in stack are : "<< sobj -> Count()<< "\n";

    cout << "poped element is : "<< sobj -> pop()<< "\n";

    sobj -> Display();

    cout << "Number of elements in stack are : "<< sobj -> Count()<< "\n";

    cout << "poped element is : "<< sobj -> pop()<< "\n";

    sobj -> Display();

    cout << "Number of elements in stack are : "<< sobj -> Count()<< "\n";

    sobj -> push('E');

    sobj -> Display();

    cout << "Number of elements in stack are : "<< sobj -> Count()<< "\n";

    delete sobj;

    //////////////////////////////////////////////////////////////////////////////////

    Queue<double> *qobj = new Queue<double>();

    qobj -> enqueue(11.56789);
    qobj -> enqueue(21.56789);
    qobj -> enqueue(51.56789);
    qobj -> enqueue(101.56789);
    
    qobj -> Display();

    cout << "Number of elements in Queue are : "<< qobj -> Count()<< "\n";

    cout << "Removed element is : "<< qobj -> dequeue()<< "\n";

    qobj -> Display();

    cout << "Number of elements in Queue are : "<< qobj -> Count()<< "\n";

    cout << "Removed element is : "<< qobj -> dequeue()<< "\n";

    qobj -> Display();

    cout << "Number of elements in Queue are : "<< qobj -> Count()<< "\n";

    qobj -> enqueue(121.56789);

    qobj -> Display();

    cout << "Number of elements in Queue are : "<< qobj -> Count()<< "\n";

    delete qobj;

    //////////////////////////////////////////////////////////////////////////////

    return 0;
}