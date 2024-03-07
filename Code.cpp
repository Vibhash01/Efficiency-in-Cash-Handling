#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> denominations = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

std::vector<int> makeChange(int amount, int amountPaid) {
    int changeAmount = amountPaid - amount; // Calculate the change amount
    std::vector<int> change(denominations.size(), 0); // Initialize counts of each denomination to 0
    
    for (size_t i = 0; i < denominations.size(); ++i) {
        while (denominations[i] <= changeAmount) {
            changeAmount -= denominations[i]; // Subtract denomination from remaining change amount
            ++change[i]; // Increment count of current denomination
        }
    }
    
    return change;
}

void displayChange(const std::vector<int>& change) {
    int totalChange = 0; // Initialize total change amount to 0
    std::cout << "Optimal Change:\n";
    for (size_t i = 0; i < denominations.size(); ++i) {
        if (change[i] > 0) {
            std::cout << "₹" << denominations[i] << ": " << change[i] << "\n";
            totalChange += denominations[i] * change[i]; // Calculate total change amount
        }
    }
    std::cout << "Total Change Amount: ₹" << totalChange << "\n"; // Display total change amount
}

int main() {
    int amount, amountPaid;
    std::cout << "Enter the amount to be paid (in ₹): ";
    std::cin >> amount;
    
    std::cout << "Enter the amount paid by the user (in ₹): ";
    std::cin >> amountPaid;
    
    if(amountPaid < amount) {
        std::cout << "\nInsufficient amount paid. \nAdditional amount required: ₹" << amount - amountPaid << "\n";
        return 0;
    }

    std::vector<int> change = makeChange(amount, amountPaid);
    displayChange(change);
    
    return 0;
}
