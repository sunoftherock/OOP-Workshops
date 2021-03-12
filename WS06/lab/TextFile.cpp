#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include <cstring>
using namespace std;
namespace sdds {
    Line::operator const char* () const {
        return (const char*)m_value;
    }
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strlen(lineValue) + 1];
        strcpy(m_value, lineValue);
        return *this;
    }
    Line::~Line() {
        delete[] m_value;
    }

    void TextFile::setEmpty() {
        delete[] m_textLines;
        delete[] m_filename;
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
        delete[] m_filename;
        m_filename = nullptr;

        if (!(isCopy)) {
            m_filename = new char[strlen(fname) + 1];
            strcpy(m_filename, fname);
        }
        else {
            m_filename = new char[strlen(fname) + 3];
            strcpy(m_filename, "C_");
            strcat(m_filename, fname);
        }
    };

    void TextFile::setNoOfLines() {
        char currentChar;
        ifstream myfile(m_filename);
        int lineCount = 0;
        if (*this) {
            if (myfile.is_open()) {
                do {
                    myfile.get(currentChar);
                    if (currentChar == '\n') {
                        lineCount++;
                    }
                } while (!myfile.eof());
            }

        }
        m_noOfLines = lineCount;
    }

    void TextFile::loadText() {
        unsigned i = 0;
        if (*this) {
            string line;
            delete[] m_textLines;
            m_textLines = new Line[m_noOfLines];

            fstream myfile(m_filename);
            if (myfile.is_open()){
                while (getline(myfile, line)) {
                    m_textLines[i] = line.c_str();
                    i++;
                }
            }
                myfile.close();
        }
    };

    void TextFile::saveAs(const char* fileName)const {
        ofstream newfile(fileName);
        for (unsigned i = 0; i < m_noOfLines; i++) {
            newfile << m_textLines[i].m_value;
        }
        newfile.close();
    };

    TextFile::TextFile(unsigned pageSize) {
        setEmpty();
        m_pageSize = pageSize;
    };

    TextFile::TextFile(const char* filename, unsigned pageSize) {
        setEmpty();
        m_pageSize = pageSize;
        if (filename[0] != NULL) {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
        else {
            m_textLines = nullptr;
            m_noOfLines = 0;
        }
    }

    TextFile::TextFile(const TextFile& other) {
        if (*this != other) {
            m_pageSize = other.m_pageSize;
            setEmpty();
            if (other) {
                setFilename(other.m_filename, true);
                other.saveAs(m_filename);
                setNoOfLines();
                loadText();
            }
        }
    }

    TextFile& TextFile::operator=(const TextFile& other) {
        if (*this && other) {
            delete[] m_textLines;
            other.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
        return *this;
    }

    TextFile::~TextFile() {
        delete[] m_textLines;
        delete[] m_filename;
    }

    unsigned TextFile::lines()const {
        return m_noOfLines;
    }

    ostream& TextFile::view(ostream& ostr)const {
        unsigned remaininglines;
        //validity check
        if (*this) {
            ostr << m_filename << '\n';
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << '\n';

            remaininglines = m_noOfLines;
            while (remaininglines > 0) {
                for (unsigned i = 0; i < m_pageSize && i < remaininglines; i++) {
                    ostr << m_textLines[i];
                    remaininglines--;
                }
                if (remaininglines >= m_pageSize) {
                    ostr << "Hit ENTER to continue...";
                    getchar();
                }
            }
        }
        return ostr;
    }

    istream& TextFile::getFile(istream& istr) {
        string line;
        getline(istr, line);
        setFilename(line.c_str());
        setNoOfLines();
        loadText();
        return istr;
    }

    const char* TextFile::operator[](unsigned index)const {
        if (*this) {
            return m_textLines[index % m_noOfLines];
        }
        else return NULL;
    }

    TextFile::operator bool()const {
        return (m_filename);
    }

    const char* TextFile::name()const {
        return m_filename;
    }

    ostream& operator<<(ostream& ostr, const TextFile& text) {
        text.view(ostr);
        return ostr;
    }

    istream& operator>>(istream& istr, TextFile& text) {
        text.getFile(istr);
    }
}

