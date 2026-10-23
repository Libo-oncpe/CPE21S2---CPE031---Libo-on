#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <iomanip>

#define Max_size 100

//matching pairs
const std::unordered_map<char, char> pair = {
    {'1', '1'},
    {'2', '2'},
    {'3', '3'},
    {'4', '4'},
    {'5', '5'},
    {'6', '6'},
    {'7', '7'},
    {'8', '8'},
    {'9', '9'},
    {'0', '0'},
};

//opening characters
bool isOpening (char ch) {
    return ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '0';
}
//closing characters
bool isClosing (char ch) {
    return pair.count(ch) > 0;
}
//stacks using array
class Array {
    //stacks pushed elements
    private:
    char arr[Max_size];
    int topIndex;
    //top is always -1 of the arr size
    public:
    Array() : topIndex(-1){}
//push function
    bool push(char val){
        //checks if stacks is full
        if (topIndex >= Max_size - 1) return false;
        arr[++topIndex] = val;
        return true;
    }
//pop function
    char pop(){
        //empty returns null
        if (isEmpty()) return '\0';
        return  arr[topIndex--];
    }
//top function
    char top() const {
        if(isEmpty()) return '\0';
        return arr[topIndex];
    }

//isEmpty function
    bool isEmpty() const {
        return topIndex < 0;     
    }
};

//array checking if the opening and closing characters match
bool checkArray(const std::string& expr){
    Array stack;
    for (char ch : expr) {
        if (isOpening(ch)){
            stack.push(ch);
        } else if (isClosing(ch)){
            if (stack.isEmpty() || stack.pop() != pair.at(ch)) {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

//Linked List
struct Node{
    char data;
    Node* next;
};

class LinkedList {
    private:
    Node* topNode;

    public:
    LinkedList() : topNode(nullptr){}

    ~LinkedList() {
        while(isEmpty()){
            pop();
        }
    }
//push function
    void push(char val) {
        Node* newNode = new Node();
        newNode ->data = val;
        newNode ->next = topNode;
        topNode = newNode;
    }
//pop function
    char pop() {
        if (isEmpty()) return '\0';
        Node* temp = topNode;
        char poppedVal = temp -> data;
        topNode = topNode -> next;
        delete temp;
        return poppedVal;
    }
//isEmptr function
    bool isEmpty() const{
        return topNode == nullptr;
    }
};
//linked list checking if opening and closing matches
    bool checkLinkedList(const std::string& expr){
        LinkedList stack;
        for (char ch : expr){
            if (isOpening(ch)){
                stack.push(ch);
            } else if (isClosing(ch)) {
                if (stack.isEmpty() || stack.pop() != pair.at(ch)){
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
//main function
int main() {

//test cases
    std::string testCases[] = {
        "12321",
        "12345",
        "1221",
        "7",
        "123321",
        "1234325"   
    };

    std::cout <<  "====================Symmetrical Testing====================\n\n";

    std::cout << std::left
              << std::setw(22) << "Sample"
              << std::setw(16) << "Array Stack"
              << std::setw(22) << "Linked List Stack"
              << "\n";
    std::cout <<  "==========================================================\n";          
//displaying results
    for (const std::string& expr : testCases) {
        bool resArr = checkArray(expr);
        bool resLL =  checkLinkedList(expr);

        std::cout << std::left
                << std::setw(22) << expr
                << std::setw(16) << (resArr ? "Symmetrical" : "Asymmetrical")
                << std::setw(22) << (resLL ? "Symmetrical" : "Asymmetrical")
                << "\n";
        }
    return 0;
}