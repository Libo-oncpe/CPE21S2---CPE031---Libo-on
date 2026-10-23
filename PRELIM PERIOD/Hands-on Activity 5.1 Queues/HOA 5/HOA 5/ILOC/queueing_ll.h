#ifndef queueing_ll_h
#define queueuing_ll_h
#include <iostream>
#include <string>

// job class 
class job {
public: 
    std::string username; 
    int NumofPages;
    int id;    
    
// class members and initializers
    job() {
        id = 0;
        username = "";
        NumofPages = 0;
    }

    job(int jobID, std::string name, int pages) {
        id = jobID;
        username = name;
        NumofPages = pages;
    }
};

// create a class node
template <typename T>
class qNode {
public:
    T data; 
    qNode* next;
};

// new node creator
template<typename T>
qNode<T>* new_node(T newData) {
    // allocate space for the new node
    qNode<T>* newNode = new qNode<T>;
    // store the newData to the newNode
    newNode->data = newData;
    // point newNode next to null
    newNode->next = nullptr;
    return newNode;
}

// enqueue
template<typename T>
void enqueue(T newData, qNode<T>** frontptr, qNode<T>** backptr) {
    // create a new node
    qNode<T>* newNode = new_node(newData);
    // check if the queue is empty 
    if ((*frontptr) == nullptr && (*backptr) == nullptr) {
        (*frontptr) = newNode;
        (*backptr) = newNode;
        return;
    }
    // if not then insert at the back
    (*backptr)->next = newNode;
    (*backptr) = newNode;
}

// dequeue
template<typename T>
void dequeue(qNode<T>** frontptr, qNode<T>** backptr) {
    // check if the queue is empty
    if ((*frontptr) == nullptr && (*backptr) == nullptr) {
        std::cout << "The queue is empty." << std::endl;
        return;
    }   
    // create a temporary variable to store the node to be deleted
    qNode<T>* deleteTemp = nullptr;
    // assign the current front to deleteTemp
    deleteTemp = (*frontptr);
    // check if the queue has only 1 item
    if ((*frontptr)->next == nullptr && (*backptr)->next == nullptr) {
        // means only one item is in the queue
        (*frontptr) = nullptr;
        (*backptr) = nullptr;
        delete deleteTemp;
        return;     
    }
    (*frontptr) = (*frontptr)->next;
    deleteTemp->next = nullptr;
    // delete the node
    delete deleteTemp;
}
// displayall
template<typename T> 
void display(const qNode<T>* frontptr) {
    if (frontptr == nullptr) {
        std::cout << "The queue is empty." << std::endl;
        return;
    }    
    const qNode<T>* temp = frontptr;
    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp->next != nullptr) {
            std::cout << "";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

// isempty
template <typename T>
bool isEmpty(qNode<T>** frontPtr, qNode<T>** backPtr) {
    return ((*frontPtr) == nullptr && (*backPtr) == nullptr);
}
// Printer class managing job queue
class Printer {
private:
    qNode<job>* front;
    qNode<job>* back;
public:
    Printer() {
        front = nullptr;
        back = nullptr;
    }
    void addjob(int id, std::string user, int pages) {
        job newjob(id, user, pages);
        enqueue(newjob, &front, &back);
    }
    void processNextJob() {
        if (isEmpty(&front, &back)) {
            std::cout << "No pending jobs to process.\n";
            return;
        }
        std::cout << "Processing: " << front->data << std::endl;
        dequeue(&front, &back);
    }
    void processAllJobs() {
        std::cout << "\nProcessing All Pending Jobs...\n";
        while (!isEmpty(&front, &back)) {
            processNextJob();
        }
        std::cout << "All jobs processed.\n";
    }
    void displayQueue() {
        std::cout << "\nCurrent Queue: " << std::endl;
        display(front);
    }
    ~Printer() {
        while (!isEmpty(&front, &back)) {
            dequeue(&front, &back);
        }
    }
};

#endif