#ifndef SDDS_SUBJECT_H
#define SDDS_SUBJECT_H
namespace sdds {
   class Item {
      char m_itemName[21];
      double m_price;
      bool m_taxed;
      void setName(const char* name);
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
   };
}

#endif // !SDDS_SUBJECT_H
