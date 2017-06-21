#ifndef EX4_WET_LIST_H
#define EX4_WET_LIST_H

#include <iostream>
#include <assert.h>

using namespace std;

template <class T> class Link;
template <class T> class Iterator;

template <class T>
class List {
    int size;
    Iterator<T> list_head;
    Iterator<T> list_end;

    int find_index(const T& element) const;

    static const int HEAD_INDEX = 0;

public:

    List();

    List(const List&);

    ~List();

    List& operator=(const List&);

    class Link;

    class Iterator;

    Iterator begin() const;

    Iterator end() const;

    void insert(const T& data, Iterator<T> iterator);

    void insert(const T& data);

    void remove(Iterator<T> iterator);

    Iterator<T> find(const Predicate& predicate);

    void sort(const Compare& compare);

    int getSize();

};

template <class T>
class List<T>::Iterator{
    Link<T>* current;

    friend class List<T>;

public:

    Iterator();

    Iterator(const Iterator<T> iterator);

    const T& operator*() const{
        return current->data;
    };

    Iterator& operator++();

    Iterator operator++(int);

    Iterator& operator--();

    Iterator operator--(int);

    bool operator==(const Iterator& iterator) const;

    bool operator!=(const Iterator& iterator) const;

    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
};

template <class T>
class List<T>::Link{
    T data;
    Link<T>* next;
    Link<T>* previous;

    Link(const T& data, Link<T>* next = HEAD_INDEX,
         Link<T>* previous = HEAD_INDEX):
            data(data),
            next(next),
            previous(previous){};

    friend class List<T>;
    friend class Iterator<T>;
};


template <class T>
const T& Iterator::operator*() const {
    return curren
}

template <class T>
List<T>::Iterator::


#endif //EX4_WET_LIST_H
