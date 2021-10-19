#ifndef POLICY_H_
#define POLICY_H_

#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>



class Policy
{
public:
    Policy();
    explicit Policy(int policy_number, double price, double payment_amount, int code_of_type, int customer_code, int employee_code);

    ~Policy();

    int getPolicyNumber() const;
    void setPolicyNumber(int new_policy_number);

    const std::string& getDateOfStart() const;
    void setDateOfStart(const std::string& new_date_of_start);

    const std::string& getDateOfEnd() const;
    void setDateOfEnd(const std::string& new_date_of_end);

    double getPrice() const;
    void setPrice(double new_price);

    double getPaymentAmount() const;
    void setPaymentAmount(double new_payment_amount);

    int getCodeOfType() const;
    void setCodeOfType(int new_code_of_type);

    bool getPayStatus() const;
    void makePayed() const;

    bool getClosedStatus() const;
    void close() const;

    int getCustomerCode() const;
    void setCustomerCode(int new_customer_code);

    int getEmployeeCode() const;
    void setEmployeeCode(int new_employee_code);

    static void doLongTimeOperation();

    void display() const;

private:
    int policy_number_;
    std::string date_of_start_;
    mutable std::string date_of_end_;
    double price_;
    double payment_amount_;
    int code_of_type_;
    mutable bool is_payed_;
    mutable bool is_closed_;
    int customer_code_;
    int employee_code_;

    void checkForClosed() const;
    static std::string getCurrentTime();
};


#endif  // POLICY_H_
