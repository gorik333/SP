#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"




int displayMenu();
void createPolicy(Records::Database& inDB);
void makePayed(Records::Database& inDB);
void close(Records::Database& inDB);


int main()
{
    Records::Database policyDB;
    bool done = false;
    while (!done) {
        int selection = displayMenu();
        switch (selection) {
            case 1:
                createPolicy(policyDB);
                break;
            case 2:
                makePayed(policyDB);
                break;
            case 3:
                close(policyDB);
                break;
            case 4:
                policyDB.displayAll();
                break;
            case 5:
                policyDB.displayCurrent();
                break;
            case 0:
                done = true;
                break;
            default:
                std::cerr << "Unknown command." << std::endl;
    }
  }
}


int displayMenu()
{
    int selection;

    std::cout << std::endl;

    std::cout << "Policy Database"                   << std::endl;
    std::cout << "-----------------"                 << std::endl;
    std::cout << "1) Create and write policy"        << std::endl;
    std::cout << "2) Make the policy payed"          << std::endl;
    std::cout << "3) Close an policy"                << std::endl;
    std::cout << "4) List all policyes"              << std::endl;
    std::cout << "5) List all current policies"      << std::endl;
    std::cout << "0) Quit"                           << std::endl;
    std::cout                                        << std::endl;

    std::cout << "---> ";
    std::cin >> selection;

    return selection;
}



void createPolicy(Records::Database& inDB)
{
    int policy_number;
    double price, payment_amount;
    int code_of_type, customer_code, employee_code;
    
    std::cout << "Policy number: ";
    std::cin >> policy_number;
    std::cout << "Price: ";
    std::cin >> price;
    std::cout << "Payment amount: ";
    std::cin >> payment_amount;
    std::cout << "Code of type: ";
    std::cin >> code_of_type;
    std::cout << "Customer code: ";
    std::cin >> customer_code;
    std::cout << "Employee code: ";
    std::cin >> employee_code;

    inDB.addPolicy(policy_number, price, payment_amount, code_of_type, customer_code, employee_code);
}


void makePayed(Records::Database& inDB)
{
    int policyNumber;

    std::cout << "Policy number? ";
    std::cin >> policyNumber;

    try {
        inDB.getPolicy(policyNumber).makePayed();
        std::cout << "Policy " << policyNumber << " has been terminated." << std::endl;
    } catch (...) {
        std::cerr << "Unable to terminate policy!" << std::endl;
    }
}


void close(Records::Database& inDB)
{
    int policyNumber;

    std::cout << "Policy number? ";
    std::cin >> policyNumber;

    try {
        inDB.getPolicy(policyNumber).close();
    } catch (...) {
        std::cerr << "Unable to promote policy!" << std::endl;
    }
}
