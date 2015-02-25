#include "list.h"

#define NULL ((void *)0)

template <typename T>
Node<T>::Node(T d, Node<T> * n, Node<T> * p) {
    data = d;
    next = n;
    prev = p;
}

template <typename T>
Node<T>::Node(T d, Node * n) {
    data = d;
    next = n;
    prev = NULL;
}

template <typename T>
Node<T>::Node(T d) {
    data = d;
    next = NULL;
    prev = NULL;
}

template <typename T>
List<T>::List() {
    head = NULL;
    tail = NULL;
}

template <typename T>
void List<T>::push_front(T element) {
    Node<T> * node = new Node<T>(element, head);
    if (head != NULL) {
        head->prev = node;
    }
    head = node;
    if (tail == NULL) {
        tail = node;
    }
}

template <typename T>
T List<T>::peek_front() {
    return head->data;
}

template <typename T>
void List<T>::pop_front() {
    Node<T> * node = head->next;
    delete head;
    head = node;
    if (node != NULL) {
        node->prev = NULL;
    } else {
        tail = head;
    }
}

template <typename T>
void List<T>::push_back(T element) {

}

template <typename T>
T List<T>::peek_back() {

}

template <typename T>
void List<T>::pop_back() {

}

template <typename T>
bool List<T>::empty() {
    return head == NULL && tail == NULL;
}

template <typename T>
Node<T> * List<T>::begin() {
    return head;
}

template <typename T>
Node<T> * List<T>::end() {
    return NULL;
}

template <typename T>
Node<T> * List<T>::last() {
    return tail;
}

template <typename T>
int List<T>::size() {
    int result = 0;
    
    for (Node<T> * pointer = head; pointer != NULL; pointer = pointer->next) {
        result++;
    }
    
    return result;
}
