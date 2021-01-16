#ifndef DNODE_H_INCLUDED
#define DNODE_H_INCLUDED

template <typename T>
class dnode{
public:
    T data;
    dnode<T> *next;
    dnode<T> *previous;

    dnode(){
        next = nullptr;
        previous = nullptr;
    }
    dnode(T item, dnode<T> *nextNode = nullptr, dnode<T> *prevNode = nullptr){
        data = item;
        next = nextNode;
        previous = prevNode;
    }
};


#endif // DNODE_H_INCLUDED

