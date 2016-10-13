//*****************************************************************
//  LinkedList.cpp
//  HashTable
//
//  Created by Aniketh Sukhtankar on October 11, 2016.
//
//  This header file contains the Linked List class declaration.
//  Hash Table array elements consist of Linked List objects.
//*****************************************************************

#include "LinkedList.h"

// Constructs the empty linked list object.
// Creates the head node and sets length to zero.
LinkedList::LinkedList()
{
    head = new Item;
    head -> next = NULL;
    length = 0;
}

// Inserts an item at the end of the list.
void LinkedList::insertItem( Item * newItem )
{
    if (!head -> next)
    {
        head -> next = newItem;
        length++;
        return;
    }
    Item * p = head;
    Item * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
    }
    p -> next = newItem;
    newItem -> next = NULL;
    length++;
}

// Removes an item from the list by item key.
// Returns true if the operation is successful.
bool LinkedList::removeItem( string itemKey )
{
    if (!head -> next) return false;
    Item * p = head;
    Item * q = head;
    while (q)
    {
        if (q -> key == itemKey)
        {
            p -> next = q -> next;
            delete q;
            length--;
            return true;
        }
        p = q;
        q = p -> next;
    }
    return false;
}

// Searches for an item by its key.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
Item * LinkedList::getItem( string itemKey )
{
    Item * p = head;
    Item * q = head;
    while (q)
    {
        p = q;
        if ((p != head) && (p -> key == itemKey))
            return p;
        q = p -> next;
    }
    return NULL;
}

// Displays list contents to the console window.
void LinkedList::printList()
{
    if (length == 0)
    {
        cout << "\n\n";
        return;
    }
    Item * p = head;
    Item * q = head;
    cout << "\n\n ";
    while (q)
    {
        p = q;
        if (p != head)
        {
            //cout << p -> key;
            cout <<"\ndiscipline :    "<< p -> discipline;
            cout <<"\ngender :        "<< p -> gender;
            cout <<"\nteam or ind :   "<< p -> isTeam;
            cout <<"\nevent :         "<< p -> event;
            cout <<"\nvenue :         "<< p -> venue;
            cout <<"\nmedal :         "<< p -> medal;
            cout <<"\nathlete :       "<< p -> athlete;
            cout <<"\ncountry :       "<< p -> country;
            if (p -> next) cout << "\n\n";
            else cout << " ";
        }
        q = p -> next;
    }
    cout << "\n\n";
}

// Returns the length of the list.
int LinkedList::getLength()
{
    return length;
}

// De-allocates list memory when the program terminates.
LinkedList::~LinkedList()
{
    Item * p = head;
    Item * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
        if (q) delete p;
    }
}

//*****************************************************************
// End of File
//*****************************************************************
