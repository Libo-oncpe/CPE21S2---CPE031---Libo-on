#include <iostream>
#include "queue_ll.h"


int main(){
    qNode<char>* front =  nullptr;
    qNode<char>* back = nullptr;

    enqueue('H', &front, &back);
    std::cout << "Front: " << front -> data << " Back: " << back -> data << std::endl;
    enqueue('A', &front, &back);
    std::cout << "Front: " << front -> data << " Back: " << back -> data << std::endl;
    enqueue('R', &front, &back);
    std::cout << "Front: " << front -> data << " Back: " << back -> data << std::endl;
    
    std::cout << "Testing the dequeue operator \n";
    dequeue(&front, &back);
    std::cout << "Front: " << front -> data << " Back: " << back -> data << std::endl;
    dequeue(&front, &back);
    std::cout << "Front: " << front -> data << " Back: " << back -> data << std::endl;


    std::cout << "Testing the display operator \n";
    display(front);
    enqueue('H', &front, &back);
    display(front);
    enqueue('A', &front, &back);
    (front);
    enqueue('R', &front, &back);
    display(front);

    std::cout << "Is Empty? " << (isEmpty(&front, &back) ? "Yes" : "No") << std::endl;
    return 0;

}