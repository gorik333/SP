#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"



namespace Records
{
    Database::Database()
    {
        // pass
    }


    Database::~Database() 
    {
        // pass
    }


    void Database::addPolicy(int policy_number, double price, double payment_amount, int code_of_type, int customer_code, int employee_code)
    {
        Policy policy;

        policy.setPolicyNumber(policy_number);
        policy.setPrice(price);
        policy.setPaymentAmount(payment_amount);
        policy.setCodeOfType(code_of_type);
        policy.setEmployeeCode(customer_code);
        policy.setCustomerCode(employee_code);

        policies_.push_back(policy);
    }


    const Policy& Database::getPolicy(int policy_number)
    {
        for (const auto& policy: policies_)
        {
            if (policy.getPolicyNumber() == policy_number)
            {
                return policy;
            }
        }

        throw std::out_of_range("No matching policy.");
    }


    void Database::displayAll()
    {
        for (const auto& policy: policies_)
        {
            policy.display();
        }
    }


    void Database::displayCurrent()
    {
        for (const auto& policy: policies_)
        {
            if (!policy.getClosedStatus())
            {
                policy.display();
            }
        }
    }
}
