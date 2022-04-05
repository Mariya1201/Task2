#include "headers.h"

void CString1::output() {
    ofstream outputFile(fileName, std::ios::binary | std::ios::app);
    if (!outputFile) {
        cerr << "\nError: file " << fileName <<" not found!" << endl;
        throw -1;
    }

    outputFile << "\n";
    for (int i = 0; i < this->dataSize; ++i) {
        outputFile << this->data[i];

        if (i + 1 != this->dataSize) {
            outputFile << "\n";
        }
    }

    outputFile.close();
}

CString1::~CString1() {}
