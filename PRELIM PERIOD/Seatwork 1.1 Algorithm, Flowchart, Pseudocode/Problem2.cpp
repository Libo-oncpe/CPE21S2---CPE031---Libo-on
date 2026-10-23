#include <iostream>
#include <iomanip>

int main(){

    float price, payment, change, total;
    std::string item;
    std::cout << "Welcome to the Cashiering System.\n";
    
//system asks for item name and price of up to 3 items
    for (int i = 1; i <= 3; i++) {
        std::cout << "Enter item " << i << " name and price: ";
        std::cin >> item >> price;
        total += price;

    }
        std::cout << "The total is: " << total << " pesos.\n";
        std::cout << "Please enter your payment. ";
        std::cin >> payment;
        change = payment - total;
        
//verifies how much is the change of the user or if they have sufficient funds
    if (change == 0) {
        std::cout << "You have no change. Thank you for shopping with us";
    } else if (change > 0) {
        std::cout << "Your change is " << change << " pesos. Thank you for shopping with us";
    } else {
        std::cout << "You have insufficient funds. Please try again.";
    }
    
    return 0;
}
