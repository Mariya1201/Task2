#include "headers.h"

void CString0::output() {
    ofstream outputFile(fileName, std::ios::binary | std::ios::app);
    if (!outputFile) {
        cerr << "\nError: file " << fileName <<" not found!" << endl;
        throw -1;
    }
    outputFile << "\n";
    for (int i = 0; i < dataSize; ++i) {
        outputFile << data[i];

        if (i + 1 != dataSize) {
            outputFile << ' ';
        }
    }

    outputFile.close();
}

CString0::~CString0() {}

CString0 operator+(const CString& first, const CString& second) {
    int size1 = first.getDataSize();
    int size2 = second.getDataSize();

    int dataSize = size1 + size2;
    char *data = new char[dataSize];
    int i = 0;
    for (i = 0; i < size1; i++) {
        data[i] = first.get(i);
    }
    for (int j = 0; j < size2; j++) {
        data[j+i] = second.get(j);
    }

    CString0 c(first.getFileName(), data, dataSize);
    return c;
}
