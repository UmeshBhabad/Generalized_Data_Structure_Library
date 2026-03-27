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
    Doubly Circular             DoublyCLLnode                       DoublyCLL       Done
    Stack                       Stacknode                           Stack           Done
    Queue                       Queuenode                           Queue           Done
    BST                             -                               
    Sorting                         -
    Searching                       -
*/

#ifndef LIBRARY_DS_H
#define LIBRARY_DS_H

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
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        
        void Display();
        int Count();
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
// Description :        Used to insert node at first position
// Input :              Data of node
// Output :             Nothing
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      InsertLast
// Description :        Used to insert node at last position
// Input :              Data of node
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      DeleteFirst
// Description :        Used to Delete node at first position
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      DeleteLast
// Description :        Used to Delete node at last position
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      Display
// Description :        Used to Display all nodes in LL
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T> *temp = NULL;
    int iCnt = 0;
    temp = this -> first;

    for(iCnt = 1; iCnt <= this -> iCount; iCnt++)   // Updated : Using for loop
    {
        cout << "| "<< temp -> data <<" | ->";
        temp = temp -> next;
    }
    cout<< "NULL"<< "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      Count
// Description :        Used to Count nodes in LL
// Input :              Nothing
// Output :             Count of nodes
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> :: Count()
{
    return (this -> iCount);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      InsertAtPos
// Description :        Used to insert node at given position
// Input :              data of node, position
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      DeleteAtPos
// Description :        Used to remove node at given position
// Input :              position
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      InsertFirst
// Description :        Used to insert node at first position
// Input :              Data of node
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      InsertLast
// Description :        Used to insert node at last position
// Input :              Data of node
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      InsertAtPos
// Description :        Used to insert node at given position
// Input :              data of node, position
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      DeleteFirst
// Description :        Used to Delete node at first position
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      DeleteLast
// Description :        Used to Delete node at last position
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      DeleteAtPos
// Description :        Used to remove node at given position
// Input :              position
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      Display
// Description :        Used to Display all nodes in LL
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      Count
// Description :        Used to Count nodes in LL
// Input :              Nothing
// Output :             Count of nodes
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      InsertFirst
// Description :        Used to insert node at first position
// Input :              Data of node
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      InsertLast
// Description :        Used to insert node at last position
// Input :              Data of node
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      InsertAtPos
// Description :        Used to insert node at given position
// Input :              data of node, position
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      DeleteFirst
// Description :        Used to Delete node at first position
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      DeleteLast
// Description :        Used to Delete node at last position
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      DeleteAtPos
// Description :        Used to remove node at given position
// Input :              position
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      Display
// Description :        Used to Display all nodes in LL
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      Count
// Description :        Used to Count nodes in LL
// Input :              Nothing
// Output :             Count of nodes
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL <T> :: Count()
{
    return this -> iCount;
}

/////////////////////////////////////////////////////////////////////////
//          Doubly Circular Linked List using Generic Approach
/////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      InsertFirst
// Description :        Used to insert node at first position
// Input :              Data of node
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      InsertLast
// Description :        Used to insert node at last position
// Input :              Data of node
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      InsertAtPos
// Description :        Used to insert node at given position
// Input :              data of node, position
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      DeleteFirst
// Description :        Used to Delete node at first position
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      DeleteLast
// Description :        Used to Delete node at last position
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      DeleteAtPos
// Description :        Used to remove node at given position
// Input :              position
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      Display
// Description :        Used to Display all nodes in LL
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      Count
// Description :        Used to Count nodes in LL
// Input :              Nothing
// Output :             Count of nodes
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCLL<T> :: Count()
{
    return this -> iCount;
}

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
        T peek();
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      push
// Description :        Used to insert node into Stack
// Input :              Data of node
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: push(T No)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(No);

    newn -> next = this -> first;
    this -> first = newn;

    this -> iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      pop
// Description :        Used to remove last node from stack
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      peek
// Description :        Used to Display Top element in Stack
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: peek()
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      Display
// Description :        Used to Display all elements in Stack
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      Count
// Description :        Used to Count elements in Stack
// Input :              Nothing
// Output :             Count of nodes
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      enqueue
// Description :        Used to insert node into Queue
// Input :              Data of node
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      dequeue
// Description :        Used to remove node from Queue(FIFO)
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      Display
// Description :        Used to Display all nodes in queue
// Input :              Nothing
// Output :             Nothing
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

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
        cout << "| " << temp -> data << " | - ";
        temp = temp -> next; 
    }
    cout<< "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :      Count
// Description :        Used to Count nodes in queue
// Input :              Nothing
// Output :             Count of nodes
// Author :             Umesh Shivaji Bhabad
// Date :               27/03/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int Queue<T> :: Count()
{
    return this -> iCount;
}

///////////////////////////////// End of Library ///////////////////////////////////////////////////////////
#endif