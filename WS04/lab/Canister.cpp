 #define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {
    double PI = 3.14159265;

    //This function sets the attributes to their default values. 
    //It sets the content name pointer to null, height to 13.0, diameter to 10.0, content volume to 0.0 and usable flag to true.
    void Canister::setToDefault() {

        m_contentName = nullptr;
        m_height = 13.0;
        m_diameter = 10.0;
        m_contentVolume = 0;
        m_usable = true;
    };

    //Sets the content name of the current Canister.
    //If the incoming Cstr is not null and the Canister is usable, it will delete the current content name, 
    // allocate memory to the length of Cstr (+1 for null) and copies the Cstr into the newly allocated memory. 
    //Otherwise, it will silently do nothing.
    void Canister::setName(const char* Cstr) {
        if (Cstr != nullptr){
            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr);
        }

    };

    //Returns true is the content volume is less than 0.00001 CCs.
    bool Canister::isEmpty()const {
        return (m_contentVolume < 0.00001);

    };

    //Compares the content name of this Canister with the one received from the argument C. Using strCmp in cstring.h, 
    //it returns true if both content names are not null and are identical. Otherwise, it returns false;
    bool Canister::hasSameContent(const Canister& C)const {
        return (strCmp(C.m_contentName, m_contentName));
    };

    //default constructor
    Canister::Canister() {
        setToDefault();
    }

    //Single argument constructor
    Canister::Canister(const char* contentName) {
        setToDefault();
        setName(contentName);
    }

    //three argument constructor
    Canister::Canister(double height, double diameter, const char* contentName) {
        setToDefault();
        if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <=30.0) {
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0;
            setName(contentName);
        }
        else {
            m_usable = false;
        };

    };

    Canister::~Canister() {
        delete[]   m_contentName;
    };

    void Canister::clear() {
        delete[] m_contentName;
        setToDefault();
    }

    double Canister::capacity()const {
        return (PI * (m_diameter / 2) * (m_diameter / 2) * (m_height-0.267));
    }

    double Canister::volume()const {
        return (m_contentVolume);
    }

    Canister& Canister::setContent(const char* contentName) {
        if (contentName == nullptr) {
            m_usable = false;
        }
        else if (isEmpty()) {
            setName(contentName);
        }
        else if (strCmp(contentName,m_contentName)) {
            m_usable = false;
        }
        return *this;
    };

    Canister& Canister::pour(double quantity) {
        if (m_usable && quantity > 0 && ((quantity + m_contentVolume) < capacity())) {
            m_contentVolume += quantity;
        }
        else {
            m_usable = false;
        }
        return *this;
    }

    Canister& Canister::pour(Canister& C) {
        setContent(C.m_contentName);

            if (C.m_contentVolume > (capacity() - m_contentVolume)) {
                C.m_contentVolume -= (capacity() - m_contentVolume);
                m_contentVolume = capacity();
            }
            else {
                pour(C.m_contentVolume);
                C.m_contentVolume = 0;
            }
        return *this;
    }

    ostream& Canister::display()const {
        cout.width(7);
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << capacity();
        cout << "cc (" << m_height << "x" << m_diameter << ") Canister";

        if (!(m_usable)) {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != nullptr) {
            cout << " of ";
            cout.width(7);
            cout << m_contentVolume;
            cout << "cc   " << m_contentName;
        }
        return cout;
    }
};