#include <iostream>
#include <string.h>
#include <vector>

class User
{
private:
    int balance;
    std::string name, account_no, pin;

public:
    User();
    User(std::string, std::string, std::string, int);
    // setter and getter
    void setPin(std::string);
    std::string getPin();
    void setBalance(int);
    int getBalance();
    void setName(std::string);
    std::string getName();
    void setAccountNo(std::string);
    std::string getAccountNo();

    // Utility
    // void createUser(std::string, std::string, std::string, int);
};
// Constructor

// void User::createUser()
// {
//     this->setName(name);
//     this->setAccountNo(acc_no);
//     this->setPin(pin);
//     this->setBalance(balance);
// }

User::User()
{
    this->balance = 0;
}

User::User(std::string name, std::string acc_no, std::string pin, int balance)
{
    this->name = name;
    this->balance = balance;
    this->account_no = acc_no;
    this->pin = pin;
}

// All the setter and getter goes here

void User::setPin(std::string pin)
{
    this->pin = pin;
    std::cout << "Pin Set Successfully." << std::endl;
}

std::string User::getPin()
{
    return this->pin;
}

void User::setBalance(int balance)
{
    this->balance = balance;
}

int User::getBalance()
{
    return this->balance;
}

void User::setName(std::string name)
{
    this->name = name;
    std::cout << "Name Added Successfully." << std::endl;
}

std::string User::getName()
{
    return this->name;
}

void User::setAccountNo(std::string acc_no)
{
    this->account_no = acc_no;
    std::cout << "Account Number Added Successfully." << std::endl;
}

std::string User::getAccountNo()
{
    return this->account_no;
}

// end of setter and getter

class Bank_Management
{
    std::vector<User> user_arr;

public:
    void addUser(User);
    void showAccountDetails(std::string);
    int showUserNumber();
};

// This is the Section of Utility Function

void Bank_Management::addUser(User user)
{
    this->user_arr.push_back(user);
}

int Bank_Management::showUserNumber()
{
    return this->user_arr.size();
}

void Bank_Management::showAccountDetails(std::string acc_no)
{
    for (int i = 0; i < this->user_arr.size(); i++)
    {
        if (this->user_arr.at(i).getAccountNo() == acc_no)
        {
            std::cout << "A/C No: " << this->user_arr.at(i).getAccountNo() << std::endl;
            std::cout << "Account Holder Name: " << this->user_arr.at(i).getName() << std::endl;
            std::cout << "PIN: " << this->user_arr.at(i).getPin() << std::endl;
            std::cout << "Balance: " << this->user_arr.at(i).getBalance() << "\n\n"
                      << std::endl;
            return;
        }
    }
    std::cout << "User Not Found" << std::endl;
}

Bank_Management bank;

int main()
{
    int balance, option = 10;
    std::string name, acc_no, pin;

    while (option != 0)
    {
        std::cout << "Select an Option From Below: " << std::endl;
        std::cout << "1. Create an Account." << std::endl;
        std::cout << "2. Balance Check." << std::endl;
        std::cout << "3. Withdraw Money." << std::endl;
        std::cout << "4. Add Money." << std::endl;
        std::cout << "5. Change PIN" << std::endl;
        std::cout << "6. Delete Account." << std::endl;
        std::cout << "7. Show Account Details." << std::endl;
        std::cout << "8. Show Total User." << std::endl;
        std::cout << "9. Show all Account." << std::endl;
        std::cout << "Select Option: ";
        std::cin >> option;
        system("cls");
        std::cin.ignore(1, '\n');
        if (option == 1)
        {
            std::cout << "Enter Your Name: ";
            std::getline(std::cin, name);
            std::cout << "Enter Your A/C No: ";
            std::cin >> acc_no;
            std::cout << "Enter Your PIN: ";
            std::cin >> pin;
            std::cout << "Enter Your Initial Deposit: ";
            std::cin >> balance;
            User u(name, acc_no, pin, balance);
            bank.addUser(u);
            std::cout << "User Successfully Created." << std::endl;
        }
        else if (option == 7)
        {
            std::cout << "Enter Your A/C Number: ";
            std::cin >> acc_no;
            system("cls");
            bank.showAccountDetails(acc_no);
        }
        else if (option == 8)
        {
            std::cout << "Number of Total User: " << bank.showUserNumber() << std::endl;
        }
    }

    return 0;
}