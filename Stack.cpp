// Implementation file for linked StackType
#include "StackType.h"

// Class constructor
template<class T>
StackType<T>::StackType() {
    topPtr = nullptr;
}

// Class destructor
template<class T>
StackType<T>::~StackType() {
    while (topPtr != nullptr) {
        Node *temp; = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}

// Determines whether the stack is full
template<class T>
bool StackType<T>::IsFull() const {
    try {
        Node *location = new Node;
        delete location;
        return false;
    }
    catch (std::bad_alloc error) {
        return true;
    }
}

// Determines whether the stack is empty
template<class T>
bool StackType<T>::IsEmpty() const {
    return (topPtr == nullptr);
}

// Adds newItem to the top of the stack
template<class T>
void StackType<T>::Push(T item) {
    if (IsFull())
        throw FullStack();
    else {
        Node *location = new Node;
        location->info = item;
        location->next = topPtr;
        topPtr = location;
    }
}

// Removes top item from the stack
template<class T>
void StackType<T>::Pop() {
    if (IsEmpty())
        throw EmptyStack();
    else {
        Node *temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}

// Returns a copy of top item on the stack
template<class T>
T StackType<T>::Top() {
    if (IsEmpty())
        throw EmptyStack();
    else
        return topPtr->info;
}