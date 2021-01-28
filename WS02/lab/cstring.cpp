// Workshop 1: DIY
// Date: 1/24/2021
// Author: Ruoqi Sun
// Student #: 135388205
// Class: OOP224
///////////////////////////////////////////////////
#include <iostream>
using namespace std;

namespace sdds {
    void strCpy(char* des, const char* src) {
        //initializes variable
        int i = 0;
        //iterates until null terminator, and replaces each letter of destination from source
        while (src[i] != '\0') {
            des[i] = src[i];
            i++;
        }
        //puts a null terminator at the end of the new string
        des[i] = '\0';
    };

    void strnCpy(char* des, const char* src, int len) {
        int i;
        // iterates over the list, and up to the length len
        for (i = 0; i < len; i++) {
            // replaces each letter in des with src
            des[i] = src[i];
        };
    };

    int strCmp(const char* s1, const char* s2) {
        int i = 0, difference = 0;
        // a while loop that will reapeat until one of the letters is a null terminator
        // inner loop will keep checking if letter in s1 is different from s2 at every index
        // will break out if there's a difference, or one has ended.
        do {

            if (s1[i] > s2[i]) {
                difference = 1;
                break;
            }
            else if (s1[i] < s2[i]) {
                difference = -1;
                break;
            }
            i++;
        } while (s1[i - 1] != '\0' && s2[i - 1] != '\0');

        //if iteration complete and difference not changed, means string completely the same
        return difference;
    }

    int strnCmp(const char* s1, const char* s2, int len) {
        int i = 0, difference = 0;

        do {

            if (s1[i] > s2[i]) {
                difference = 1;
                break;
            }
            else if (s1[i] < s2[i]) {
                difference = -1;
                break;
            }
            i++;
            // same functionality, just added i<len as a condition for loop to stop
        } while (i < len && s1[i - 1] != '\0' && s2[i - 1] != '\0');
        return difference;
    };

    int strLen(const char* s) {
        int length = 0;
        //iterates until null terminator reached, returns a counter
        while (s[length] != '\0') {
            length++;
        }
        return length;
    }

    const char* strStr(const char* str1, const char* str2) {

        //uses strLen to get lengths of both strings
        int len2 = strLen(str2), len1 = strLen(str1), i;

        //iterates over the length of the main string
        for (i = 0; i < len1; i++) {
            //if first letter of substring is found in main string, start check
            if (str1[i] == str2[0]) {
                //uses strnCmp to check if entire substring exists from that letter
                if (strnCmp(&str1[i], str2, len2) == 0) {
                    //if true, returns the pointer of the main string starting from that letter
                    return &str1[i];
                };
            }

        }
        //if no matches are found, nullptr is returned as no match
        return nullptr;
    }

    void strCat(char* des, const char* src) {
        //gets the lenght of the destination string using strLen
        int length = strLen(des);
        //copys the src string and appends it to the end of the destination string's pointer
        strCpy(&des[length], src);
    }
}