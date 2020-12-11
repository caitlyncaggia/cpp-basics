#include <iostream>
using namespace std;

struct Element
{
    int data;
    Element * nextPtr;
};  //end of Element

void PrintList(Element *); //Function prototype

void DeleteList(Element *); //Function prototype

int main()
{

    Element *startPtr = NULL;
    Element *currPtr = NULL;

    //Let's make the first element in the linked list
    startPtr = new Element;
    currPtr = startPtr;
    currPtr->data = 1;
    // (*currPtr).data = 1;

    for (int i=2; i<=5; i++)
    {
	currPtr->nextPtr = new Element;
        currPtr = currPtr->nextPtr;
        currPtr->data = i;
    }//end of for loop
    
    currPtr->nextPtr = NULL;
  
    PrintList(startPtr);

    DeleteList(startPtr);

}//end of main

void DeleteList(Element * curr)
{
    Element * next;

    while (curr != NULL)
    {
        next = curr->nextPtr;
        delete curr;
        curr = next;
    }//end while loop

} //end of DeleteList


void PrintList(Element * begin)
{

    while (begin !=NULL)
    {
        cout << "Data: " << begin->data << endl;
        begin = begin->nextPtr;
    }

}//end PrintList













