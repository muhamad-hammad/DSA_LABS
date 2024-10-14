// Suppose you are developing a bank account management system, and you have defined the
// BankAccount class with the required constructors. You need to demonstrate the use of these
// constructors in various scenarios.
// a) Default Constructor Usage:
// Create a default-initialized BankAccount object named account1. Print out the balance of
// account1.
// b) Parameterized Constructor Usage:
// Create a BankAccount object named account2 with an initial balance of $1000. Print out the
// balance of account2.
// c) Copy Constructor Usage:
// Using the account2 you created earlier, create a new BankAccount object named account3 using
// the copy constructor. Deduct $200 from account3 and print out its balance. Also, print out the
// balance of account2 to ensure it hasn&#39;t been affected by the transaction involving account3. Note:
// assume the variables in your case and print out the details.


#include <iostream>
using namespace std;

class Bank {
    private:
        string accountHolderName;
        int balance;
        static int account_no;

    public:
    // Default constructor
        Bank() {
            accountHolderName = "Unknown";
            balance = 0;
            account_no++;
        }
    // Parameterized constructor
        Bank(int balance) {
            this->accountHolderName = "Unknown";
            this->balance = balance;
            account_no++;
        }
    // Copy constructor(Rule of 3)
        Bank(const Bank &obj) {
            this->accountHolderName = obj.accountHolderName;
            this->balance = obj.balance;
            account_no++;
        }
        // Copy assignment operator
        Bank& operator=(const Bank &obj) {
            if (this != &obj) {
                this->accountHolderName = obj.accountHolderName;
                this->balance = obj.balance;
                account_no++;
            }
            return *this;
        }
        // Destructor
        ~Bank() {
            account_no--;
        }
        void deduct(int amount) {
            balance -= amount;
        }
        void display() {
            cout << "Account Holder Name: " << accountHolderName << endl;
            cout << "Account No: " << account_no << endl;
            cout << "Balance: " << balance << endl;
        }
};

int Bank::account_no = 0;

int main() {
    Bank account1;
    account1.display();
    Bank account2(1000);
    account2.display();
    Bank account3(account2);
    account3.deduct(200);
    account3.display();
    account2.display();
    return 0;
}