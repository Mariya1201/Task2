#ifndef __CSTRING_1_INCLUDED__
#define __CSTRING_1_INCLUDED__

#include "headers.h"


class CString1 : public CString {
    public:
        CString1() : CString() {};
        CString1(string _fileName, const char* _data, int _dataSize) : CString(_fileName, _data, _dataSize) {};
        CString1(const CString& other) : CString(other) {};

        using CString::operator=;

        void output() override final;

        ~CString1();
};

#endif
