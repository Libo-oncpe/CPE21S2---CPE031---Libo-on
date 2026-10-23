#ifndef queue_ll_h
#define queue_ll_h
#include <iostream>

//create a class node
template <typename T>
class qNode{
    public:
        T data; 
        qNode* next;
};
//new node creator
template<typename T>
qNode<T>* new_node(T newData){
    //allocate a space for the new node
    qNode<T>* newNode = new qNode<T>;

    //store the newdata to the newNode
    newNode -> data = newData;

    //point to newNode next to null
    newNode -> next = nullptr;

    return newNode;
}

//enqueue
template<typename T>
void enqueue(T newData, qNode<T>** frontptr, qNode<T>** backptr){

    //create a new node
    qNode<T>* newNode = new_node(newData);
    //check if the queue is empty 
    if((*frontptr) == nullptr && (*backptr) == nullptr){
        (*frontptr) = newNode;
        (*backptr) = newNode;
        return;
    }
    //if not then insert at the back
    (*backptr) -> next = newNode;
    (*backptr) = newNode;
};

//dequeue
template<typename T>
void dequeue(qNode<T>** frontptr, qNode<T>** backptr){
    //check if the queue is empty
    if((*frontptr) == nullptr && (*backptr) == nullptr){
        std::cout << "THE QUEUE IS EMPTY." << std::endl;
        return;
    }   
    //create a temporary variable to store the node to be deleted
    qNode<T>* deleteTemp = nullptr;
    //assign the current front to the deleteTemp
    deleteTemp = (*frontptr);
    //check if the queue has only 1 item
    if((*frontptr)->next == nullptr && (*backptr)->next == nullptr){
        //means only one item is in the queue
        (*frontptr) = nullptr;
        (*backptr) = nullptr;
        delete deleteTemp;
        return;     
    }
    (*frontptr) = (*frontptr) -> next;
    deleteTemp -> next = nullptr;
    
    //delete the node
    delete deleteTemp;
};
//displayall
template<typename T> 
void display(const qNode<T>* frontptr) {

    if(frontptr==nullptr){
        std::cout << "The queue is empty." << std::endl;
        return;
    }    
    const qNode<T>* temp = frontptr;
    while(temp != nullptr){
        std::cout << temp -> data;

        if(temp ->next != nullptr){
            std::cout << "->";
        }
        temp = temp ->next;
    }
    std::cout << std::endl;
};
//isempty
template <typename T>
bool isEmpty(qNode<T>** frontPtr, qNode<T>** backPtr) {
   return ((*frontPtr) == nullptr && (*backPtr) == nullptr);
}
#endif