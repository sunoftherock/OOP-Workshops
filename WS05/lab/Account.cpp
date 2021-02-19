#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account`
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    };

    Account::operator bool() const { return (m_number >= 10000 && m_number <= 99999 && m_balance >= 0); };

    Account::operator int() const { return m_number; };

    Account::operator double() const { return m_balance; };

    bool Account::operator ~() const { return (m_number == 0); }

    Account& Account::operator=(int number) {
        if (~*this) {
            if (number >= 10000 && number <= 99999) {
                m_number = number;
            }
            else
                setEmpty();
        }
        return *this;
    };

    Account& Account::operator=(Account& right_side) {
        if (~*this && bool(right_side)) {
            m_number = right_side.m_number;
            m_balance = right_side.m_balance;
            right_side.m_balance = 0;
            right_side.m_number = 0;
        }
        return *this;
    };

    Account& Account::operator+=(double added_amt) {
        if (added_amt >= 0 && bool(*this)) {
            m_balance += added_amt;
        }
        return *this;
    };

    Account& Account::operator-=(double reduce_amt) {
        if (reduce_amt >= 0 && bool(*this) && m_balance >= reduce_amt) {
            m_balance -= reduce_amt;
        }
        return *this;
    }

    Account& Account::operator<<(Account& right_side) {
        if (bool(*this) && bool(right_side) && (this->m_number != right_side.m_number)) {
            *this += right_side.m_balance;
            right_side.m_balance = 0;
        }
        return *this;
    };

    Account& Account::operator>>(Account& right_side) {
        if (bool(*this) && bool(right_side) && (this->m_number != right_side.m_number)) {
            right_side += this->m_balance;
            this->m_balance = 0;
        }
        return *this;
    };

    double operator+(const Account& left, const Account& right) {
        double sum = 0;
        if (bool(left) && bool(right)) {
            sum = double(left) + double(right);
        }
        return sum;
    };

    double operator+=(double& left, const Account& right) {
        left += (double)right;
        return left;
    };
}