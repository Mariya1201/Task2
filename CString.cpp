#include "headers.h"


CString::CString() {}

CString::CString(string _fileName,  const char* _data, int _dataSize) {
    fileName = _fileName;
    dataSize = _dataSize;

    data = new char[dataSize];
    //strcpy_s(data, _data);
    for (int k = 0; k < dataSize; k++) {
        data[k] = _data[k];
    }
}

CString::CString(const CString& other) {
    fileName = other.getFileName();
    dataSize = other.getDataSize();

    data = new char[dataSize];
   //strcpy_s(data, other.getData());
    for (int k = 0; k < dataSize; k++) {
        data[k]= other.get(k);
    }
}


CString& CString::operator=(const CString& other) {
    fileName = other.getFileName();
    dataSize = other.getDataSize();

    data = new char[dataSize];
    //strcpy_s(data, other.getData());
    for (int k = 0; k < dataSize; k++) {
        data[k]=other.get(k);
    }
    return *this;
}

CString& CString::operator=(string str) {
    dataSize = str.length();
    data = new char[dataSize];
    //strcpy_s(data, str.c_str());
    for (int k = 0; k < dataSize; k++) {
        data[k] = str[k];
    }
    return *this;
}

char CString::operator[](unsigned int i) {
    return get(i);
}

char CString::get(int i) const {
    if (i >= 0 && i <= dataSize) {
        return data[i];
    }
    return NULL;
}

string CString::getFileName() const {
    return fileName;
}

char* CString::getData() const {
    return data;
}

int CString::getDataSize() const {
    return dataSize;
}

void CString::printData() {
    cout << data << endl;
}

CString::~CString() {
    fileName = "";
    delete[] data;
}



