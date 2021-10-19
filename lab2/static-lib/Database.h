#include <iostream>
#include <vector>
#include "Policy.h"

#pragma once



namespace Records
{


    class Database
    {
    public:
        Database();
        ~Database();

        void addPolicy(int policy_number, double price, double payment_amount, int code_of_type, int customer_code, int employee_code);
        Policy const& getPolicy(int policy_number);

        void displayAll();
        void displayCurrent();
        void displayFormer();
        
    protected:
        std::vector<Policy> policies_;
    };


}
