#pragma once

template <typename T>
class Node {
    private:
        T data;
        Node<T>* next;
    public:
        Node(T d, Node<T>* n);
        void setData(T d);
        void setNext(Node<T>* n);
        T getData();
        Node* getNext();
        ~Node();
};
