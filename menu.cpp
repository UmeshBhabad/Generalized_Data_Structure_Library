/////////////////////////////////////////////////////////////////////////
// CUI based application to demonstrate the library function(Use)
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdbool.h>

/////////////////////////////////////////////////////////////////////////
// include custom Header file
/////////////////////////////////////////////////////////////////////////

#include "library_ds.h"

/////////////////////////////////////////////////////////////////////////

using namespace std;

void SinglyLLLMenu()
{
    SinglyLLL<int> *slobj = new SinglyLLL<int>();
    
    int iChoice = 0;
    int Value = 0;
    int Pos = 0;
    int iRet = 0;

    while(1)    // Uncondition loop
    {
        cout << "\n";
        cout << "==================================================================================\n";
        cout << "========================= Singly Linear Linked List  Menu ========================\n";
        cout << "==================================================================================\n";
        cout << "---------------------------- Please Select the option ----------------------------\n";
        cout << "1. Insert at first position of Linked List\n";
        cout << "2. Insert at the End of Linked List\n";
        cout << "3. Insert at specific position in the Linked List\n";
        cout << "4. Delete First Node\n";
        cout << "5. Delete Last Node\n";
        cout << "6. Delete Node at specific position\n";
        cout << "7. Display all the elements from Linked List\n";
        cout << "8. Display Total Node Count\n";
        cout << "0. Return to Main Menu\n";
        cout << "---------------------------------------------------------------------------------\n";
        cin >> iChoice;
        cout << "==================================================================================\n";


        switch (iChoice)
        {
        case 1:
            cout << "Enter the element that you want to insert : \n";
            cin >> Value;
            slobj -> InsertFirst(Value);
            cout<< "Element inserted Sucessfully\n";
            break;
        case 2:
            cout << "Enter the element that you want to insert : \n";
            cin >> Value;
            slobj -> InsertLast(Value);
            cout<< "Element inserted Sucessfully\n";
            break;
        case 3:
            cout << "Enter the element that you want to insert : \n";
            cin >> Value;
            cout << "Enter the position at which you want to insert : \n";
            cin >> Pos;
            slobj -> InsertAtPos(Value, Pos);
            cout<< "Element inserted Sucessfully\n";
            break;
        case 4:
            slobj -> DeleteFirst();
            cout << "Node Deleted Sucessfully\n";
            break;
        case 5:
            slobj -> DeleteLast();
            cout << "Node Deleted Sucessfully\n";
            break;
        case 6:
            cout << "Enter the position at which you want to remove the Node : \n";
            cin >> Pos;
            slobj -> DeleteAtPos(Pos);
            cout << "Node Deleted Sucessfully\n";
            break;
        case 7:
            cout << "\n";
            cout<<"Element of the Linked List are : \n";
            slobj -> Display();
            break;
        case 8:
            cout << "Total Count of Elements in the Linked List is : \n";
            break;
        case 0:
            cout<<"Returning to Main Menu\n";
            delete slobj;
            return;
        
        default:
            cout << "Please enter the Valid input\n";
            break;
        } // End of switch
        iRet = slobj -> Count();
        cout << "Current Node Count : " << iRet << "\n";
        cout << "\n";

    }// End of while
}

void SinglyCLLMenu()
{
    SinglyCLLL<int> *scobj = new SinglyCLLL<int>();
    
    int iChoice = 0;
    int Value = 0;
    int Pos = 0;
    int iRet = 0;

    while(1)    // Uncondition loop
    {
        cout << "\n";
        cout << "==================================================================================\n";
        cout << "======================== Singly Circular Linked List  Menu =======================\n";
        cout << "==================================================================================\n";
        cout << "---------------------------- Please Select the option ----------------------------\n";
        cout << "1. Insert at first position of Linked List\n";
        cout << "2. Insert at the End of Linked List\n";
        cout << "3. Insert at specific position in the Linked List\n";
        cout << "4. Delete First Node\n";
        cout << "5. Delete Last Node\n";
        cout << "6. Delete Node at specific position\n";
        cout << "7. Display all the elements from Linked List\n";
        cout << "8. Display Total Node Count\n";
        cout << "0. Return to Main Menu\n";
        cout << "---------------------------------------------------------------------------------\n";
        cin >> iChoice;
        cout << "==================================================================================\n";

        switch (iChoice)
        {
        case 1:
            cout << "Enter the element that you want to insert : \n";
            cin >> Value;
            scobj -> InsertFirst(Value);
            cout<< "Element inserted Sucessfully\n";
            break;
        case 2:
            cout << "Enter the element that you want to insert : \n";
            cin >> Value;
            scobj -> InsertLast(Value);
            cout<< "Element inserted Sucessfully\n";
            break;
        case 3:
            cout << "Enter the element that you want to insert : \n";
            cin >> Value;
            cout << "Enter the position at which you want to insert : \n";
            cin >> Pos;
            scobj -> InsertAtPos(Value, Pos);
            cout<< "Element inserted Sucessfully\n";
            break;
        case 4:
            scobj -> DeleteFirst();
            cout << "Node Deleted Sucessfully\n";
            break;
        case 5:
            scobj -> DeleteLast();
            cout << "Node Deleted Sucessfully\n";
            break;
        case 6:
            cout << "Enter the position at which you want to remove the Node : \n";
            cin >> Pos;
            scobj -> DeleteAtPos(Pos);
            cout << "Node Deleted Sucessfully\n";
            break;
        case 7:
            cout << "\n";
            cout<<"Element of the Linked List are : \n";
            scobj -> Display();
            break;
        case 8:
            cout << "Total Count of Elements in the Linked List is : \n";
            break;
        case 0:
            cout<<"Returning to Main Menu\n";
            delete scobj;
            return;
        
        default:
            cout << "Please enter the Valid input\n";
            break;
        } // End of switch
        iRet = scobj -> Count();
        cout << "Current Node Count : " << iRet << "\n";
        cout << "\n";

    }// End of while
}

void DoublyLLLMenu()
{
    DoublyLLL <char>*dlobj = new DoublyLLL<char>();
    
    int iChoice = 0;
    int Value = 0;
    int Pos = 0;
    int iRet = 0;

    while(1)    // Uncondition loop
    {
        cout << "\n";
        cout << "==================================================================================\n";
        cout << "========================= Doubly Linear Linked List  Menu ========================\n";
        cout << "==================================================================================\n";
        cout << "---------------------------- Please Select the option ----------------------------\n";
        cout << "1. Insert at first position of Linked List\n";
        cout << "2. Insert at the End of Linked List\n";
        cout << "3. Insert at specific position in the Linked List\n";
        cout << "4. Delete First Node\n";
        cout << "5. Delete Last Node\n";
        cout << "6. Delete Node at specific position\n";
        cout << "7. Display all the elements from Linked List\n";
        cout << "8. Display Total Node Count\n";
        cout << "0. Return to Main Menu\n";
        cout << "---------------------------------------------------------------------------------\n";
        cin>> iChoice;
        cout << "==================================================================================\n";

        switch (iChoice)
        {
        case 1:
            cout << "Enter the element that you want to insert : \n";
            cin >> Value;
            dlobj -> InsertFirst(Value);
            cout<< "Element inserted Sucessfully\n";
            break;
        case 2:
            cout << "Enter the element that you want to insert : \n";
            cin >> Value;
            dlobj -> InsertLast(Value);
            cout<< "Element inserted Sucessfully\n";
            break;
        case 3:
            cout << "Enter the element that you want to insert : \n";
            cin >> Value;
            cout << "Enter the position at which you want to insert : \n";
            cin >> Pos;
            dlobj -> InsertAtPos(Value, Pos);
            cout<< "Element inserted Sucessfully\n";
            break;
        case 4:
            dlobj -> DeleteFirst();
            cout << "Node Deleted Sucessfully\n";
            break;
        case 5:
            dlobj -> DeleteLast();
            cout << "Node Deleted Sucessfully\n";
            break;
        case 6:
            cout << "Enter the position at which you want to remove the Node : \n";
            cin >> Pos;
            dlobj -> DeleteAtPos(Pos);
            cout << "Node Deleted Sucessfully\n";
            break;
        case 7:
            cout << "\n";
            cout<<"Element of the Linked List are : \n";
            dlobj -> Display();
            break;
        case 8:
            cout << "Total Count of Elements in the Linked List is : \n";
            break;
        case 0:
            cout<<"Returning to Main Menu\n";
            delete dlobj;
            return;
        
        default:
            cout << "Please enter the Valid input\n";
            break;
        } // End of switch
        iRet = dlobj -> Count();
        cout << "Current Node Count : " << iRet << "\n";
        cout << "\n";

    }// End of while
}

void DoublyCLLMenu()
{
    DoublyCLL<int> *dcobj = new DoublyCLL<int>();
    
    int iChoice = 0;
    int Value = 0;
    int Pos = 0;
    int iRet = 0;

    while(1)    // Uncondition loop
    {
        cout << "\n";
        cout << "==================================================================================\n";
        cout << "======================== Doubly Circular Linked List  Menu =======================\n";
        cout << "==================================================================================\n";
        cout << "---------------------------- Please Select the option ----------------------------\n";
        cout << "1. Insert at first position of Linked List\n";
        cout << "2. Insert at the End of Linked List\n";
        cout << "3. Insert at specific position in the Linked List\n";
        cout << "4. Delete First Node\n";
        cout << "5. Delete Last Node\n";
        cout << "6. Delete Node at specific position\n";
        cout << "7. Display all the elements from Linked List\n";
        cout << "8. Display Total Node Count\n";
        cout<<"0. Return to Main Menu\n";
        cout << "---------------------------------------------------------------------------------\n";
        cin>> iChoice;
        cout << "==================================================================================\n";

        switch (iChoice)
        {
        case 1:
            cout << "Enter the element that you want to insert : \n";
            cin >> Value;
            dcobj -> InsertFirst(Value);
            cout<< "Element inserted Sucessfully\n";
            break;
        case 2:
            cout << "Enter the element that you want to insert : \n";
            cin >> Value;
            dcobj -> InsertLast(Value);
            cout<< "Element inserted Sucessfully\n";
            break;
        case 3:
            cout << "Enter the element that you want to insert : \n";
            cin >> Value;
            cout << "Enter the position at which you want to insert : \n";
            cin >> Pos;
            dcobj -> InsertAtPos(Value, Pos);
            cout<< "Element inserted Sucessfully\n";
            break;
        case 4:
            dcobj -> DeleteFirst();
            cout << "Node Deleted Sucessfully\n";
            break;
        case 5:
            dcobj -> DeleteLast();
            cout << "Node Deleted Sucessfully\n";
            break;
        case 6:
            cout << "Enter the position at which you want to remove the Node : \n";
            cin >> Pos;
            dcobj -> DeleteAtPos(Pos);
            cout << "Node Deleted Sucessfully\n";
            break;
        case 7:
            cout << "\n";
            cout<<"Element of the Linked List are : \n";
            dcobj -> Display();
            break;
        case 8:
            cout << "Total Count of Elements in the Linked List is : \n";
            break;
        case 0:
            cout<<"Returning to Main Menu\n";
            delete dcobj;
            return;
        
        default:
            cout << "Please enter the Valid input\n";
            break;
        } // End of switch
        iRet = dcobj -> Count();
        cout << "Current Node Count : " << iRet << "\n";
        cout << "\n";

    }// End of while
}

void StackMenu()
{
    Stack <char>*sobj = new Stack<char>();
    
    int iChoice = 0;
    int Value = 0;
    int Pos = 0;
    int iRet = 0;

    while(1)    // Uncondition loop
    {
        cout << "\n";
        cout << "==================================================================================\n";
        cout << "=================================== Stack Menu ===================================\n";
        cout << "==================================================================================\n";
        cout << "---------------------------- Please Select the option ----------------------------\n";
        cout<<"1. Insert new element into Stack\n";
        cout<<"2. Remove element from Stack\n";
        cout<<"3. Display Top element\n";
        cout<<"4. Display Stack\n";
        cout<<"5. Total Count of elements in Stack\n";
        cout<<"0. Return to Main Menu\n";
        cout << "---------------------------------------------------------------------------------\n";
        cin>> iChoice;
        cout << "==================================================================================\n";

        switch (iChoice)
        {
        case 1:
            cout << "Enter the element that you want to insert : \n";
            cin >> Value;
            sobj -> push(Value);
            cout<< "Element inserted Sucessfully\n";
            break;
        case 2:
            cout << "Poped element is : "<< sobj -> pop()<< "\n";
            break;
        case 3:
            cout << "Element at the top of the Stack is : " << sobj -> peek() << endl;
            break;
        case 4:
            sobj -> Display();
            break;
        case 5:
            cout << "Count of Elements in the Stack is : \n";
            break;
        case 0:
            cout<<"Returning to Main Menu\n";
            delete sobj;
            return;
        
        default:
            cout << "Please enter the Valid input\n";
            break;
        } // End of switch
        iRet = sobj -> Count();
        cout << "Current Node Count : " << iRet << "\n";
        cout << "\n";

    }// End of while
}

void QueueMenu()
{
    Queue<double> *qobj = new Queue<double>();
    
    int iChoice = 0;
    int Value = 0;
    int iRet = 0;

    while(1)    // Uncondition loop
    {
        cout << "\n";
        cout << "==================================================================================\n";
        cout << "=================================== Queue Menu ===================================\n";
        cout << "==================================================================================\n";
        cout << "---------------------------- Please Select the option ----------------------------\n";
        cout<<"1. Insert new element into the queue\n";
        cout<<"2. Remove the element from the queue\n";
        cout<<"3. Display the elements from the queue\n";
        cout<<"4. Count the number of elements from the queue\n";
        cout<<"0. Return to Main Menu\n";
        cout << "---------------------------------------------------------------------------------\n";
        cin>> iChoice;
        cout << "==================================================================================\n";

        switch (iChoice)
        {
        case 1:
            cout<< "Enter the element that you want to insert : \n";
            cin>> Value;
            qobj -> enqueue(Value);
            cout<< "Element gets inserted Sucessfully\n";
            break;
        case 2:
            iRet = qobj -> dequeue();
            if(iRet != -1)
            {
                cout<< "Element removed from queue is : "<< iRet<< "\n";
            }
            break;
        case 3:
            cout<<"Element of the queue are : \n";
            qobj -> Display();
            break;
        case 4:
            iRet = qobj -> Count();
            cout << "Number of elements in queue are : \n";
            break;
        case 0:
            cout<<"Returning to Main Menu\n";
            delete qobj;
            return;
        
        default:
            cout << "Please enter the Valid input\n";
            break;
        } // End of switch
        iRet = qobj -> Count();
        cout << "Current Node Count : " << iRet << "\n";
        cout << "\n";

    }// End of while
}

int main()
{
    int iChoice = 0;

    while(1)    // Uncondition loop
    {
        cout << "==================================================================================\n";
        cout << "======================== Library Application Testing Menu ========================\n";
        cout << "==================================================================================\n";
        cout << "---------------------------- Please Select the option ----------------------------\n";
        cout << "1. Singly Linear Linked List\n";
        cout << "2. Singly Circular Linked List\n";
        cout << "3. Doubly Linear Linked List\n";
        cout << "4. Doubly Circular Linked List\n";
        cout << "5. Stack\n";
        cout << "6. Queue\n";
        cout << "7. BST\n";
        cout << "8. Sorting\n";
        cout << "9. Searching\n";
        cout << "0. Exit the Application\n";
        cout << "---------------------------------------------------------------------------------\n";
        cin>> iChoice;
        cout << "==================================================================================\n";

        // 
        
        int type = 0;
        int Value = 0;
        int Pos = 0;
        int iRet = 0;
        bool isRunning = true;

        switch (iChoice)
        {
        case 1:
            // SinglyLLL
            SinglyLLLMenu();
            break;           

        case 2:
            // SinglyCLL
            SinglyCLLMenu();
            break;

        case 3:
            // DoublyLLL
            DoublyLLLMenu();
            break;

        case 4:
            // DoublyCLL
            DoublyCLLMenu();
            break;

        case 5:
            // Stack
            StackMenu();
            break;

        case 6:
            // Queue  
            QueueMenu();
            break;

        // case 7:
        //     // BST
        //     break;

        // case 8:
        //     // Sorting
        //     break;

        // case 9:
        //     // Searching
        //     break;

        case 0:
            cout << "==================================================================================\n";
            cout << "======================= Thank you for using our application ======================\n";
            cout << "==================================================================================\n";
            return 0;
        
        default:
            cout << "Please enter the Valid input\n";
            break;
        }// End of switch
    }// End of while

    return 0;
}