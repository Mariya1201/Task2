#ifndef __CSTRING_INCLUDED__
#define __CSTRING_INCLUDED__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class CString {
    protected:
        string fileName;
        int dataSize;
        char* data;

    public:
        CString();
        CString(string _fileName, const char* _data, int _dataSize);
        CString(const CString& other);

        virtual void output() = 0;

        string getFileName() const;
        char get(int i) const;
        void printData();
        char* getData() const;
        int getDataSize() const;

        CString& operator=(const CString& other);
        CString& operator=(string str);
        char operator[](unsigned int i);

        virtual ~CString();

};

#endif
