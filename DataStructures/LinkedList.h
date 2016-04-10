//
//  LinkedList.cc
//  DataStructure
//
//  Created by Fekri kassem on 4/9/16.
//  Copyright © 2016 Fekri kassem. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

template<class T>
class Node
{
public:
    Node(const T &val) : value_(val), next_(NULL) {}
    
    Node<T>* getNext() { return next_; }

    void setNext(const Node<T>& n) { next_ = n; }

private:
    Node* next_;
    T     value_;
};

template<class T>
class LinkedList {
public:
    
    LinkedList() {}
    
    ~LinkedList() {
        Node<T>* p = head_;
        
        while (p) {
            Node<T>* n = p;
            p = p->getNext();
            delete n;
        }
    }

    Node<T>* insert(const T& val) {
        Node<T>* n = new Node<T>(val), p = head_;
        
        if (!head_) {
            head_ = n;
        }

        while (p->next) {
            p = p->getNext();
        }
        
        p->setNext(n);

        return n;
    }
    
private:
    Node<T>* head_;
};

#endif /* LinkedList_h */
