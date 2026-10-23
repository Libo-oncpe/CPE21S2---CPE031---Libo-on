#include<iostream>
#include<queue>


void displayAll(std::queue<char> copyQ);

int main(){


    //create an object
    std::queue<char> myQ;
    //use enqueue operations
    myQ.push('H');
    myQ.push('A');
    myQ.push('R');
    myQ.push('U');
    myQ.push('K');
    myQ.push('A');
    myQ.push('M');
    myQ.push('I');
    std::cout << "The current front is: " << myQ.front() << std::endl;
    std::cout << "The current back is: " << myQ.back() << std::endl;
    displayAll(myQ);
    //use dequeue operations

    myQ.pop();
    displayAll(myQ);
    myQ.pop();
    displayAll(myQ);
    myQ.pop();

    std::cout << "Is the queue empty? " << myQ.empty() << std::endl;
    return 0;
}

//note: only use the member funcions of the queue stl
        //create a copy of the queue
void displayAll(std::queue<char> copyQ){    
        //lopp until empty
    while(!copyQ.empty()){
        //display the front
        std::cout << " " << copyQ.front() << " ";
        //dequeue the front
        copyQ.pop();  
    }  
//add new line  
std::cout << std::endl;   
}