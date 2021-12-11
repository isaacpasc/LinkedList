#pragma once
#include "node.h"

template <typename T>
class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        int length;
    public:
        LinkedList();
        void addToFront(T data);
        void addToEnd(T data);
        bool addAtIndex(T data, int index);
        void removeFromFront();
        void removeFromEnd();
        void removeTheFirst(T data);
        void removeAllOf(T data);
        bool elementExists(T data);
        Node<T>* find(T data);
        int indexOf(T data);
        T retrieveFront();
        T retrieveEnd();
        T retrieve(int index);
        void printList();
        void empty();
        int getLength();
        ~LinkedList();
};
