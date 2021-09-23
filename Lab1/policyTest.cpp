#include <iostream>
#include <vector>
#include "Policy.h"




int main()
{
    std::vector<Policy> policies = {
            Policy(1, 124.12,   14.54,  1, 95, 234),
            Policy(2, 4.13,     4.54,   2, 25, 234),
            Policy(3, 124.23,   25.54,  3, 573, 125),
            Policy(4, 12.3,     45.54,  4, 123, 25),
            Policy(5, 5.12,     645.54, 5, 61, 634),
            Policy(6, 14.2,     74.54,  6, 8, 185),
            Policy(7, 7.6234,   85.54,  7, 15, 22),
            Policy(8, 64.149,   34.54,  8, 26, 14),
            Policy(9, 14.12,    7424.54, 9, 845, 235),
            Policy(10, 4.1,     736.54, 10, 1377, 12),
    };

    std::cout << '\n';
    policies.at(1).close();
    policies.at(5).close();
    policies.at(9).close();
    std::cout << '\n';

    int n = 1;
    for (const auto& iter: policies)
    {
        std::cout << "Object №"         << n                       << '\n'
                  << "Policy number: "  << iter.getPolicyNumber()  << '\n'
                  << "Date of start: "  << iter.getDateOfStart()   << '\n'
                  << "Date of end: "    << iter.getDateOfEnd()     << '\n'
                  << "Price: "          << iter.getPrice()         << '\n'
                  << "Payment amount: " << iter.getPaymentAmount() << '\n'
                  << "Code of type: "   << iter.getCodeOfType()    << '\n'
                  << "Pay status: "     << iter.getPayStatus()     << '\n'
                  << "Close status: "   << iter.getClosedStatus()  << '\n'
                  << "Customer code: "  << iter.getCustomerCode()  << '\n'
                  << "Employee code: "  << iter.getEmployeeCode()  << '\n'
                  << "\n-----------------------------------------------\n";
        n++;
    }


    std::vector<std::shared_ptr<Policy>> policies2 = {
            std::make_shared<Policy>(1, 124.12,   14.54,  1, 95, 234),
            std::make_shared<Policy>(2, 4.13,     4.54,   2, 25, 234),
            std::make_shared<Policy>(3, 124.23,   25.54,  3, 573, 125),
            std::make_shared<Policy>(4, 12.3,     45.54,  4, 123, 25),
            std::make_shared<Policy>(5, 5.12,     645.54, 5, 61, 634),
            std::make_shared<Policy>(6, 14.2,     74.54,  6, 8, 185),
            std::make_shared<Policy>(7, 7.6234,   85.54,  7, 15, 22),
            std::make_shared<Policy>(8, 64.149,   34.54,  8, 26, 14),
            std::make_shared<Policy>(9, 14.12,    7424.54, 9, 845, 235),
            std::make_shared<Policy>(10, 4.1,     736.54, 10, 1377, 12)
    };


    n = 0;
    for (const auto& iter: policies2)
    {
        n++;
        std::cout << "Object №"         << n                        << '\n';
        std::cout << "Policy number: "  << iter->getPolicyNumber()  << '\n'
                  << "Date of start: "  << iter->getDateOfStart()   << '\n'
                  << "Date of end: "    << iter->getDateOfEnd()     << '\n'
                  << "Price: "          << iter->getPrice()         << '\n'
                  << "Payment amount: " << iter->getPaymentAmount() << '\n'
                  << "Code of type: "   << iter->getCodeOfType()    << '\n'
                  << "Pay status: "     << iter->getPayStatus()     << '\n'
                  << "Close status: "   << iter->getClosedStatus()  << '\n'
                  << "Customer code: "  << iter->getCustomerCode()  << '\n'
                  << "Employee code: "  << iter->getEmployeeCode()  << '\n';

        std::cout << "\n-----------------------------------------------------\n";
    }


    return 0;
}
