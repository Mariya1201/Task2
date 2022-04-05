#include "headers.h"

int Autotest1() {
    int result = 1;

    char data1[6] = "test1";
    const char* data2 = "22";

    CString0 c1("out1.txt", data1, 5);
    CString1 c2("out2.txt", data2, 2);

    CString0 c = c1 + c2;
    int dataSize = c.getDataSize();

    char* data = new char[dataSize];
    //strcpy_s(data, c.getData());
    for (int k = 0; k < dataSize; k++) {
        data[k] = c.get(k);
    }

    //cout << data << endl;
    //c.printData();


    if (c.getFileName() != "out1.txt") {
        result = 0;
    }
    if (data[0] != 't' || data[1] != 'e' || data[2] != 's' || data[3] != 't' || data[4] != '1' || data[5] != '2' || data[6] != '2') {
        result = 0;
    }


    return result;
}

int Autotest2() {
    int result = 1;

    const char* data1 = "qw";
    const char* data2 = "dsdf";

    CString0 c1("out2_1.txt", data1, 2);
    CString1 c2("out2_2.txt", data2, 4);

    CString0 c = c1 + c2;
    int dataSize = c.getDataSize();

    char* data = new char[dataSize];
    //strcpy_s(data, c.getData());
    for (int k = 0; k < dataSize; k++) {
        data[k] = c.get(k);
    }


    //cout << data << endl;
    //c.printData();


    if (c.getFileName() != "out2_1.txt") {
        result = 0;
    }
    if (data[0] != 'q' || data[1] != 'w' || data[2] != 'd' || data[3] != 's' || data[4] != 'd' || data[5] != 'f') {
        result = 0;
    }


    return result;
}

int Autotest3() {
    int result = 1;

    const char* data = "test1";;
    CString0 c("out3.txt", data, 5);

    c = "QWER";
    data = c.getData();

    //cout << data << endl;

    if (c.getFileName() != "out3.txt") {
        result = 0;
    }
    if (data[0] != 'Q' || data[1] != 'W' || data[2] != 'E' || data[3] != 'R') {
        result = 0;
    }

    return result;
}


int Autotest() {
    if (Autotest1() * Autotest2() * Autotest3() == 1) return 1;
    return 0;
}
