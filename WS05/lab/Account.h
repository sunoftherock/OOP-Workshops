#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator ~() const;
      Account& operator=(int number);
      Account& operator=(Account& right_side);
      Account& operator+=(double added_amt);
      Account& operator-=(double reduce_amt);
      Account& operator<<(Account& right_side);
      Account& operator>>(Account& right_side);
   };
   double operator+(const Account& left, const Account& right);
   double operator+=(double& left, const Account& right);
   
}
#endif // SDDS_ACCOUNT_H_