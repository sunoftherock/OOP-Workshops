 #define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {
      //This function sets the attributes to their default values. 
      //It sets the content name pointer to null, height to 13.0, diameter to 10.0, content volume to 0.0 and usable flag to true.
      void Canister::setToDefault(){
          
          m_contentName = nullptr;
          m_hieght = 13.0;
          m_diameter = 10.0;
          m_contentVolume = 0;
          m_usable = true;
      };

      //Sets the content name of the current Canister.
      //If the incoming Cstr is not null and the Canister is usable, it will delete the current content name, 
      // allocate memory to the length of Cstr (+1 for null) and copies the Cstr into the newly allocated memory. 
      //Otherwise, it will silently do nothing.
      void Canister::setName(const char* Cstr){
          m_contentName = new char[strLen(Cstr)+1];
          strCpy(m_contentName,Cstr);
      };

      //Returns true is the content volume is less than 0.00001 CCs.
      bool Canister::isEmpty()const{
          return (m_contentVolume < 0.00001);

      };

      //Compares the content name of this Canister with the one received from the argument C. Using strCmp in cstring.h, 
      //it returns true if both content names are not null and are identical. Otherwise, it returns false;
      bool Canister::hasSameContent(const Canister& C)const{
          return (strCmp(C.m_contentName,m_contentName));
      };
   
}