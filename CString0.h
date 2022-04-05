#ifndef __CSTRING_0_INCLUDED__
#define __CSTRING_0_INCLUDED__

#include "headers.h"


class CString0 : public CString {
    public:
        CString0() : CString() {};
        CString0(string _fileName, const char* _data, int _dataSize) : CString(_fileName, _data, _dataSize) {};
        CString0(const CString& other) : CString(other) {};

        using CString::operator=;

        void output() override final;

        friend CString0 operator+(const CString& first, const CString& second);

        ~CString0();
};

#endif
