#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

// Enum for Payment Modes
enum class PaymentMode {
    PayPal,
    GooglePay,
    CreditCard,
    Unknown
};

vector<function<void(double)>> paymentHandlers = {
    // PayPal (index 0)
    [](double amount) {
        cout << "Processing PayPal payment of $" << amount << endl;
    },
    // GooglePay (index 1)
    [](double amount) {
        cout << "Processing GooglePay payment of $" << amount << endl;
    },
    // CreditCard (index 2)
    [](double amount) {
        cout << "Processing Credit Card payment of $" << amount << endl;
    },
    // Unknown (index 3)
    [](double amount) {
        cout << "Invalid payment mode selected!" << endl;
    }
};

void printPaymentsProcessing(PaymentMode mode, double amount)
{
    int index = static_cast<int>(mode);
    if (index >= 0 && index < paymentHandlers.size()) {
        paymentHandlers[index](amount);
    } else {
        paymentHandlers[static_cast<int>(PaymentMode::Unknown)](amount);
    }
}

// Checkout function
void checkout(PaymentMode mode, double amount, const function<void(PaymentMode, double)>& print = printPaymentsProcessing) {
    print(mode, amount);
}

// Example usage
int main() {
    double amount = 150.75;

    checkout(PaymentMode::PayPal, amount);
    checkout(PaymentMode::GooglePay, amount);
    checkout(PaymentMode::CreditCard, amount);
    checkout(PaymentMode::Unknown, amount);

    return 0;
}