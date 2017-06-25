#ifndef EX4_WET_LIST_H
#define EX4_WET_LIST_H

#include <iostream>
#include <assert.h>
#include <algorithm>
#include "Exceptions.h"

using namespace std;
using namespace mtm::ListExceptions;


template <class T>
class List {
    class Node {
        T data;
        Node *next;
        Node *previous;

        Node(const T &data) :
                data(data),
                next(NULL),
                previous(NULL) {};

        friend class List<T>;

        friend class Iterator;

    public:

        Node &operator=(const Node &node) = default;

    };

    int size;
    Node  *list_head;
    Node  *list_end;

    //Iterator<T> list_iterator;

    static const int HEAD_INDEX = 0; //C++ NULL
    static const int END_INDEX = 0; //C++ NULL

public:


    /*!
     * list c'tor. creates an empty list.
     */
    List();

    /*!
     * copy c'tor. constructs a new list with given list params.
     * @param list - the list to copy.
     */
    List(const List &list);

    /*!
     * a list d'to. deletes all the nodes of a given list.
     */
    ~List();

    /*!
     * an assignment operator
     * @param list - the list to be assigned.
     * @return ref to a new list that contains the assigned values.
     */
    List &operator=(const List &list);

    /*!
     * return the number of items in the linked list.
     * @return - the int number of items.
     */
    int getSize() const;

    /*!
     * function adds a new item to the list with the data value.
     * inserts at the list's end.
     * @param data - the new item's data.
     */
    void insert(const T &data);

    /*!
     * functions sorts the list according to the given Compare function.
     * @tparam Compare - function object. returns true if first param is before
     *                   second param.
     * @param compare - the compare function
     */
    template<class Compare>
    void sort(const Compare &compare);

    /*!
     * checks if two lists are equal.
     * @param list - the right hand list to compare to.
     * @return true if both lists contains the same items at the same order.
     */
    bool operator==(const List &list) const;

    /*!
     * check if two lists are NOT equal/
     * @param list - the right hand list to compare to.
     * @return the ! of ==.
     */
    bool operator!=(const List &list) const;

    class Iterator {
        const Node *current;
        const List<T> *list;

        Iterator(const List<T> *list, const Node *node) :
                current(node),
                list(list) {}

        friend class List<T>;

    public:

        //class Node;

        const T &operator*() const;

        Iterator &operator++();

        Iterator operator++(int);

        Iterator &operator--();

        Iterator operator--(int);

        bool operator==(const Iterator &iterator) const;

        bool operator!=(const Iterator &iterator) const;


        Iterator(const Iterator &iterator) = default;

        Iterator &operator=(const Iterator &iterator) = default;

    };

    /*!
     * function adds a new item to the list with the data value.
     * inserts before given iterator.
     * @param data - the new item's data.
     * @param iterator - the iterator to insert begore.
     *
     * @exception ElementNotFound in case that the given iterator is of another
     *              list.
     */
    void insert(const T &data, Iterator iterator);

    /*!
     * function removes an item off the list.
     * @param iterator - points to the item to remove.
     *
     * @exception ElementNotFound in case that the given iterator is of another
     *              list, or iterator points to the list's end.
     */
    void remove(Iterator iterator);

    /*!
     * return the Iterator to the list head.
     * @return the list head node data (the first item on the list.
     */
    Iterator begin() const;

    /*!
     * returns the iterator the list end.
     * iterator will point to NULL by the function's end.
     * @return NULL iterator
     */
    Iterator end() const;

    /*!
     * function finds an item in the list the fits the Predicate critiria.
     * @tparam Predicate - function object. returns true if an item fits.
     * @param predicate - the function object.
     * @return the iterator value of the first item that fits.
     * if no items fit, returns the list end.
     */
    template<class Predicate>
    Iterator find(const Predicate &predicate);

};

template <class T>
List<T>::List() :
        size(HEAD_INDEX),
        list_head (HEAD_INDEX),
        list_end (END_INDEX)
        /*list_iterator(this, list_head)*/{}


template <class T>
List<T>::List(const List& list) :
        size(list.getSize()),
        list_head(list.list_head),
        list_end(END_INDEX){
    for(Node *current = list.list_head; current != END_INDEX;
        current = current->next){
        insert(current->data);
    }
}

template <class T>
List<T>::~List() {
    Node *node = list_head;
    while (node != END_INDEX){
        Node *next = node->next;
        delete node;
        node = next;
    }
}

template <class T>
List<T>& List<T>::operator=(const List& list) {
    if (this == &list){
        return *this;
    }
    size = list.size;
    Node* current = list.list_head;
    //list_head = current;
    for(current; current != list.list_end;
        current = current->next){
        insert(current->data);
    }
    //list_end = current;
    return *this;
}

template <class T>
int List<T>::getSize() const {
    return this->size;
}

template <class T>
typename List<T>::Iterator List<T>::begin() const {
    return Iterator(this, list_head);
}

template <class T>
typename List<T>::Iterator List<T>::end() const {
    return Iterator(this, list_end);
}

template <class T>
void List<T>::insert(const T &data, Iterator iterator) {
    if(iterator == this->end()){
        insert(iterator.current->data);
        return;
    }
    Node *current = list_head;
    while (current != &iterator && current != list_end){
        current = current->next;
    }
    if (current == list_end){
        throw ElementNotFound();
    }
    Node *newNode = new Node(data);
    newNode->next = current;
    if(current->previous != HEAD_INDEX){
        Node *previous = current->previous;
        previous->next = newNode;
        newNode->previous = previous;
    } else {
        list_head = newNode;
        newNode->previous = HEAD_INDEX;
    }
    size++;
}

template <class T>
void List<T>::insert(const T &data) {
    Node *newNode = new Node(data);
    if(size == 0){
        list_head = newNode;
        newNode->previous = HEAD_INDEX;
        newNode->next = END_INDEX;
        size++;
        return;
    }
    Node *current = list_head;
    while (current->next != list_end){
        current = current->next;
    }
    current->next = newNode;
    newNode->previous = current;
    size++;
}

template <class T>
void List<T>::remove(Iterator iterator) {
    if (size == 0 || this != iterator.list){
        throw ElementNotFound();
    }
    Node *current = list_head;
    while (current->data != iterator.current->data && current != list_end){
        current = current->next;
    }
    if(current == list_end){
        throw ElementNotFound();
    }
    (current->previous)->next = current->next;
    (current->next)->previous = current->previous;
    delete(*current);
    size--;
}

template <class T, class Predicate>
typename List<T>::Iterator List<T>::find(const Predicate &predicate) {
    for(Node *current = list_head; current != NULL; current = current->next){
        if(predicate(current->data)){
            return Iterator(this, current);
        }
    }
    return this->end();
}

template <class T, class Compare>
void List<T>::sort(const Compare &compare) {
    if(size == 0 || size == 1){ //no sort needed
        return;
    }
    Node *current = list_head;
    while (current->next != list_end){
        if(compare(current->data, (current->next)->data) == false){
            //switch places:
            if(current->previous != list_head){
                (current->previous)->next = current->next;
                (current->next)->previous = current->previous;
            } else {
                (current->next)->previous = HEAD_INDEX;
            }
            current->previous = current->next;
            current->next = (current->next)->next;
            (current->next)->next = current;

            //return to head every time a switch was made
            current = list_head;
        }
    }
}

template <class T>
bool List<T>::operator==(const List& list) const{
    bool same = (this->size == list.size);
    if (same){
        Node *other = list.list_head;
        for (Node *current = list_head; current != list_end;
             current = current->next){
            if (other->data != current->data){
                same = false;
                break;
            }
            other = other->next;
            assert(other != list.list_end); //we checked that the list are
                                            // of the same size.
        }
    }
    return same;
}

template <class T>
bool List<T>::operator!=(const List& list) const{
    return !(*this == list);
}


template <class T>
const T& List<T>::Iterator::operator*() const {
    if(current == NULL){

    }
    return current->data;
}

template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
    current = current->next;
    return *this;
}

template <class T>
typename List<T>::Iterator List<T>::Iterator::operator++(int) {
    Iterator result = *this;
    ++*this;
    return result;
}

template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator--() {
    current = current->previous;
    return *this;
}

template <class T>
typename List<T>::Iterator List<T>::Iterator::operator--(int) {
    Iterator result = *this;
    --*this;
    return result;
}

template <class T>
bool List<T>::Iterator::operator==(const Iterator& iterator) const{
    if(current != this->list->list_end &&
            iterator.current != iterator.list->list_end){
        return (list == iterator.list &&
                current->data == iterator.current->data);
    } else{
        return (list == iterator.list);
    }
}

template <class T>
bool List<T>::Iterator::operator!=(const Iterator& iterator) const{
    return !(*this == iterator);
}

#endif //EX4_WET_LIST_H
