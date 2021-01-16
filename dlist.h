#ifndef DLIST_H_INCLUDED
#define DLIST_H_INCLUDED
#include "dnode.h"
#include <iostream>
using namespace std;

template <typename T>
class dlist{
    dnode<T> *head;

public:
    dlist(){
        head = nullptr;
    }
    dlist(T value){
        dnode<T> *firstNode;
        firstNode = new dnode<T>;

        head = firstNode;
        firstNode->previous = nullptr;
        firstNode->next = nullptr;
        firstNode->data = value;
    }
    void display(){
        if(!head){
            cout << "The list is empty." << endl;
            return;
        }
        dnode<T> *Ptr;
        Ptr = head;
        while(Ptr != NULL){
            cout << Ptr->data;
            Ptr = Ptr->next;
        }
    }
    bool del(T target) {
    dnode<T> *nodePtr;

    if (!head) {
        cout << "The list is already empty." << endl;
        return false;
    }

    nodePtr = head;
    while (nodePtr && !(nodePtr->data == target)) {
        nodePtr = nodePtr->next;
    }

   if (!nodePtr) {
        return false;
    }

    if (head == nodePtr) {
        head = head->next
        head->next->previous = head;
        head->previous = nullptr;

    }

    if (nodePtr->next) {
        nodePtr->next->previous = nodePtr->previous;
    }

    if (nodePtr->previous) {
        nodePtr->previous->next = nodePtr->next;
    }

    delete nodePtr;
    return true;
}



    void inser(T info){
        dnode<T> *newNode;
        dnode<T> *ptr;
        newNode = new dnode<T>;
        newNode->data = info;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        if(head = nullptr){
            head = newNode;
        }
        else{
            ptr = head;
            while(ptr->next != nullptr){
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->previous = ptr;
        }
    }

    void show(){
        dnode<T> *ptr;
        ptr = head;
        while(ptr != NULL){
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
    int getSize(){
        int s = 0;
        dnode<T> *ptr;
        ptr = head;
        while(ptr != NULL){
            s++;
            ptr = ptr->next;
        }
        return s;
    }
    dnode<T>* begin(){
        return head;
    }
    bool searchList(T target){
       dnode<T> *nodePtr;

    if (!head) {
        return false;
    }
    else {
        nodePtr = head;
        while (nodePtr) {
            if (nodePtr->data == target){
                cout << "Student found.\n";
                cout << nodePtr->data;
                return true;
            }
            nodePtr = nodePtr->next;
        }

        return false;
    }
    }


};



#endif // DLIST_H_INCLUDED
