#include "Policy.h"



Policy::Policy() : policy_number_(), date_of_start_(getCurrentTime()), price_(), payment_amount_(),
                   code_of_type_(), is_payed_(), is_closed_(), customer_code_(), employee_code_()
{
    std::cout << "Empty object was created: " << getCurrentTime() << '\n';
}


Policy::Policy(int policy_number, double price, double payment_amount, int code_of_type, int customer_code, int employee_code)
                : policy_number_(policy_number), date_of_start_(getCurrentTime()), price_(price), payment_amount_(payment_amount),
                code_of_type_(code_of_type), is_payed_(), is_closed_(), customer_code_(customer_code), employee_code_(employee_code)
{
    std::cout << "New object was created:\t" << getCurrentTime() << '\n';
}


Policy::~Policy()
{
    std::cout << "Object was deleted:\t" << date_of_end_ << '\n';
}


void Policy::checkForClosed() const
{
    if (is_closed_)
    {
        throw std::invalid_argument("Error! Policy has been already closed.");
    }
}


std::string Policy::getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}


int Policy::getPolicyNumber() const
{
    return policy_number_;
}


void Policy::setPolicyNumber(int new_policy_number)
{
    checkForClosed();

    policy_number_ = new_policy_number;
    std::cout << "Policy number is set\n";
}


const std::string& Policy::getDateOfStart() const
{
    return date_of_start_;
}


void Policy::setDateOfStart(const std::string& new_date_of_start)
{
    checkForClosed();

    date_of_start_ = new_date_of_start;
    std::cout << "Date of the start is set\n";
}


const std::string& Policy::getDateOfEnd() const
{
    return date_of_end_;
}


void Policy::setDateOfEnd(const std::string& new_date_of_end)
{
    checkForClosed();

    date_of_end_ = new_date_of_end;
    std::cout << "Date of the end is set\n";
}


double Policy::getPrice() const
{
    return price_;
}


void Policy::setPrice(double new_price)
{
    checkForClosed();

    price_ = new_price;
    std::cout << "The price is set.\n";
}


double Policy::getPaymentAmount() const
{
    return payment_amount_;
}


void Policy::setPaymentAmount(double new_payment_amount)
{
    checkForClosed();

    payment_amount_ = new_payment_amount;
    std::cout << "The payment amount is set.\n";
}


int Policy::getCodeOfType() const
{
    return code_of_type_;
}


void Policy::setCodeOfType(int new_code_of_type)
{
    checkForClosed();

    code_of_type_ = new_code_of_type;
    std::cout << "Code of type is set\n";
}


bool Policy::getPayStatus() const
{
    return is_payed_;
}


void Policy::makePayed()
{
    checkForClosed();

    is_payed_ = true;
    std::cout << "The policy has been payed.\n";
}


bool Policy::getClosedStatus() const
{
    return is_closed_;
}


void Policy::close()
{
    checkForClosed();

    date_of_end_ = getCurrentTime();
    is_closed_ = true;
    std::cout << "The policy has been closed.\n";
}


int Policy::getCustomerCode() const
{
    return customer_code_;
}


void Policy::setCustomerCode(int new_customer_code)
{
    checkForClosed();

    customer_code_ = new_customer_code;
    std::cout << "Customer code is set\n";
}


int Policy::getEmployeeCode() const
{
    return employee_code_;
}


void Policy::setEmployeeCode(int new_employee_code)
{
    checkForClosed();

    employee_code_ = new_employee_code;
    std::cout << "Employee code is set\n";
}


void Policy::doLongTimeOperation()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
