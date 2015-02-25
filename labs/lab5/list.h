
#ifndef _LIST_H
#define _LIST_H

template <typename T>
class Node {
public:
    Node(T d, Node * n, Node * p);
    Node(T d, Node * n);
    Node(T d);
    T data;
    Node * next;
    Node * prev;
};

template <typename T>
class List {
public:
    List();
    void push_front(T element);
    T peek_front();
    void pop_front();
    void push_back(T element);
    T peek_back();
    void pop_back();
    bool empty();
    Node<T> * begin();
    Node<T> * end();
    Node<T> * last();
    int size();
private:
    Node<T> * head;
    Node<T> * tail;
};

#endif