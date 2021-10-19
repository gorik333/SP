#include "Policy.h"



Policy::Policy() : policy_number_(), date_of_start_(getCurrentTime()), price_(), payment_amount_(),
                   code_of_type_(), is_payed_(), is_closed_(), customer_code_(), employee_code_()
{
}


Policy::Policy(int policy_number, double price, double payment_amount, int code_of_type, int customer_code, int employee_code)
                : policy_number_(policy_number), date_of_start_(getCurrentTime()), price_(price), payment_amount_(payment_amount),
                code_of_type_(code_of_type), is_payed_(), is_closed_(), customer_code_(customer_code), employee_code_(employee_code)
{
}


Policy::~Policy()
{
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
}


const std::string& Policy::getDateOfStart() const
{
    return date_of_start_;
}


void Policy::setDateOfStart(const std::string& new_date_of_start)
{
    checkForClosed();

    date_of_start_ = new_date_of_start;
}


const std::string& Policy::getDateOfEnd() const
{
    return date_of_end_;
}


void Policy::setDateOfEnd(const std::string& new_date_of_end)
{
    checkForClosed();

    date_of_end_ = new_date_of_end;
}


double Policy::getPrice() const
{
    return price_;
}


void Policy::setPrice(double new_price)
{
    checkForClosed();

    price_ = new_price;
}


double Policy::getPaymentAmount() const
{
    return payment_amount_;
}


void Policy::setPaymentAmount(double new_payment_amount)
{
    checkForClosed();

    payment_amount_ = new_payment_amount;
}


int Policy::getCodeOfType() const
{
    return code_of_type_;
}


void Policy::setCodeOfType(int new_code_of_type)
{
    checkForClosed();

    code_of_type_ = new_code_of_type;
}


bool Policy::getPayStatus() const
{
    return is_payed_;
}


void Policy::makePayed() const
{
    checkForClosed();

    is_payed_ = true;
}


bool Policy::getClosedStatus() const
{
    return is_closed_;
}


void Policy::close() const
{
    checkForClosed();

    date_of_end_ = getCurrentTime();
    is_closed_ = true;
}


int Policy::getCustomerCode() const
{
    return customer_code_;
}


void Policy::setCustomerCode(int new_customer_code)
{
    checkForClosed();

    customer_code_ = new_customer_code;
}


int Policy::getEmployeeCode() const
{
    return employee_code_;
}


void Policy::setEmployeeCode(int new_employee_code)
{
    checkForClosed();

    employee_code_ = new_employee_code;
}


void Policy::doLongTimeOperation()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
}


void Policy::display() const
{
    std::cout     << "Policy number: "  << policy_number_  << '\n'
                  << "Date of start: "  << date_of_start_  << '\n'
                  << "Date of end: "    << date_of_end_    << '\n'
                  << "Price: "          << price_          << '\n'
                  << "Payment amount: " << payment_amount_ << '\n'
                  << "Code of type: "   << code_of_type_   << '\n'
                  << "Pay status: "     << is_payed_       << '\n'
                  << "Close status: "   << is_closed_      << '\n'
                  << "Customer code: "  << customer_code_  << '\n'
                  << "Employee code: "  << employee_code_  << '\n'
                  << "\n---------------------------------------\n";
}
