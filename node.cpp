#include "node.h"

// Nodes hold data and pointer to next node

template <typename T>
Node<T>::Node(T d, Node* n) {
    data = d;
    next = n;
}

// getters/setters:

template <typename T>
void Node<T>::setData(T d) {
    data = d;
}

template <typename T>
void Node<T>::setNext(Node* n) {
    next = n;
}

template <typename T>
T Node<T>::getData() {
    return data;
}

template <typename T>
Node<T>* Node<T>::getNext() {
    return next;
}

template <typename T>
Node<T>::~Node() {

}
