#include "linkedList.h"
#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() {
    head = NULL; // head points to NULL when list empty
    length = -1; // length starts at -1 to index from 0
}

template <typename T>
void LinkedList<T>::addToFront(T data) {
    if (head==NULL) { // if list is empty new node points to NULL
        Node<T>* temp = new Node<T>(data, NULL);
        head = temp;
    } else { // new node points to head, then becomes head
        Node<T>* temp = new Node<T>(data, head);
        head = temp;
    }
    length+=1;
}

template <typename T>
void LinkedList<T>::addToEnd(T data) {
    Node<T>* temp = new Node<T>(data, NULL); // tail node always points to NULL
    if (head==NULL) { // if list is empty node becomes head
        head = temp;
	length+=1;
    } else { // add node to last index of list 
        addAtIndex(data, length+1);
    }
}

template <typename T>
bool LinkedList<T>::addAtIndex(T data, int index) {
    if (index == 0) { // index 0 is front so call this function is faster
        addToFront(data);
        return true;
    } else if (index <= length + 1) { // check if index is in bounds of list
        Node<T>* newNode = new Node<T>(data, NULL);
        Node<T>* temp = head;
        for (int i = 0; i < index-1; i++) { // loop through list from head to *one* before index value
            if (temp != NULL) {
                temp = temp->getNext();
            }
        }
        newNode->setNext(temp->getNext()); // new node points to node in front
        temp->setNext(newNode); // node behind points to new node
        length+=1;
        return true;
    } else {
        return false;
    }
}

template <typename T>
void LinkedList<T>::removeFromFront() {
    if (head != NULL && head->getNext() == NULL) { // if only one node in list
        delete head; // delete head, empty list
        length = length - 1;
    } else if (head != NULL) { // if > 1 node in list
        Node<T>* temp = head;
        head = head->getNext(); // move head pointer up one
        std::free(temp); // delete old head
        length = length - 1;
    }
}

template <typename T>
void LinkedList<T>::removeFromEnd() {
    if (head != NULL && head->getNext() == NULL) { // if only one node in list
        delete head; // delete head, empty list
        length = length - 1;
    } else if (head != NULL) { // if > 1 node in list
        Node<T>* secondLast = head;
        while ((secondLast->getNext())->getNext() != NULL) { // loop to second to last node in list
            secondLast = secondLast->getNext(); 
        }
        delete (secondLast->getNext()); // delete last node
        secondLast->setNext(NULL); // second to last node is now last, points to NULL
        length = length - 1;
    }
}

template <typename T>
void LinkedList<T>::removeTheFirst(T data) {
    if (head != NULL) { // if list isnt empty
        Node<T>* temp = head;
        while (head->getData() == data) { // if head is fist target
            head = head->getNext(); // move its pointer by one node
            length = length - 1;
            return;
        }
        while (temp->getNext() != NULL) { // loop to end of list
	    if ((temp->getNext())->getData() == data) { // if next node data == data
                temp->setNext((temp->getNext())->getNext()); // set curr node next pointer to next next node
                length = length - 1;
                return; // leave method
            } else {
                temp = temp->getNext();
            }
        }
    }
}

template <typename T>
void LinkedList<T>::removeAllOf(T data) {
    if (head != NULL) { // if list is not empty
        Node<T>* temp = head;
        while (head->getData() == data) { // if head is a target, remove it
            head = head->getNext();
            length = length - 1;
        }
        while (temp->getNext() != NULL) { // loop through list
	    if ((temp->getNext())->getData() == data) { // if next node data == data
                temp->setNext((temp->getNext())->getNext()); // set curr node next pointer to next next node
                length = length - 1;
            } else {
                temp = temp->getNext();
            }
        }
    }
}

template <typename T>
bool LinkedList<T>::elementExists(T data) {
    if (head != NULL) {
        Node<T>* temp = head;
        if (head->getData() == data) { // if data is in the head node
            return true;
        }
        while (temp->getNext() != NULL) { // loop through list
	    if ((temp->getNext())->getData() == data) { // if data is in next node
                return true;
            } else {
                temp = temp->getNext();
            }
        }
        return false;
    } else {
        return false;
    }
}

template <typename T>
Node<T>* LinkedList<T>::find(T data) {
    if (head != NULL) {
        Node<T>* temp = head;
        if (head->getData() == data) { // if data is in the head node
            return head;
        }
        while (temp->getNext() != NULL) { // loop through list
	    if ((temp->getNext())->getData() == data) { // if data is in next node
                return temp->getNext();
            } else {
                temp = temp->getNext();
            }
        }
        return NULL;
    } else {
        return NULL;
    }
}

template <typename T>
int LinkedList<T>::indexOf(T data) {
    if (head != NULL) { 
        Node<T>* temp = head;
        if (head->getData() == data) { // if data is in the head node
            return 0;
        }
        int index = 1;
        while (temp->getNext() != NULL) { // loop through list
	    if ((temp->getNext())->getData() == data) { // if data is in next node
                return index;
            } else {
                index++;
                temp = temp->getNext();
            }
        }
        return -1; // returns -1 if not found
    } else {
        return -1;
    }
}

template <typename T>
T LinkedList<T>::retrieveFront() {
    if (head != NULL) {
        return head->getData();
    } else {
        return NULL;
    }
}

template <typename T>
T LinkedList<T>::retrieveEnd() {
    if (head != NULL) {
        Node<T>* temp = head;
        for (int i = 0; i < length; i++) {
            temp = temp->getNext();
        }
        return temp->getData();
    } else {
        return NULL;
    }
}

template <typename T>
T LinkedList<T>::retrieve(int index) {
    if (head != NULL) {
        if (index == 0) {
            return head->getData();
        } else if (index <= length) {
	    Node<T>* temp = head;
            for (int i = 0; i < index; i++) {
                if (temp != NULL) {
                    temp = temp->getNext();
                }
            }
            return temp->getData();
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

template <typename T>
void LinkedList<T>::printList() {
    if (head != NULL) {
        Node<T>* temp=head;
        while(temp != NULL) {
	  std::printf("[");
	  std::cout << (temp->getData()); 
            std::printf("] ");
            temp=temp->getNext();
        }
    }
}

template <typename T>
void LinkedList<T>::empty() {
    if (head != NULL) {
        Node<T>* temp = head;
        while(head != NULL) {
            temp = head;
            head = head->getNext();
            std::free(temp);
        }
        length = -1;
    }
}

template <typename T>
int LinkedList<T>::getLength() {
    return length+1;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    empty();
}
