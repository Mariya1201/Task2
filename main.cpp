#include "headers.h"


int main() {

    if (Autotest() != 1) {
    	cerr << "Error! Tests not passed!" << endl;
    	return -1;
    }

    try {
        string fileName = "file.txt";
        int s = 0; // Количество строк в файле

        // cout << "Enter fileName ... ";
        // cin >> fileName;

        ifstream inputFile(fileName);
        if (!inputFile) {
            cerr << "\nError: file not found!" << endl;
            return -1;
        }


        string line;
        while (getline(inputFile, line)) //Узнаем сколько строк в файле
            s ++ ;
        inputFile.close();

        vector<CString*> vec;
        map<string, Factory*> factoryMap;
        factoryMap["hori"] = new Factory_hori;
        factoryMap["vert"] = new Factory_vert;
        // CString** arr = (CString**)malloc(sizeof(CString*)*s);


        int i = 0;
        string inputString;

        inputFile.open(fileName);
        while (getline(inputFile, inputString)) {
            stringstream temp(inputString);
            string type;
            string outputFilename;
            string data;

            temp >> type >> outputFilename >> data;

            int dataSize = data.length();
            char *cstr = new char[dataSize + 1];
            //strcpy_s(cstr, data.c_str());
            for (int k = 0; k < dataSize; k++) {
                cstr[k] = data[k];
            }

            auto Creator = factoryMap.find(type);
            if (Creator == factoryMap.end())
                throw runtime_error("There is no such class!");
            vec.push_back(Creator->second->create(outputFilename, cstr, dataSize));


            delete [] cstr;
            i++;
        }
        inputFile.close();

        for (auto i : vec) {
            i->output();
        }

        for (auto i : vec)
            delete i;

        cout << endl << "Done!" << endl;
        return 0;
    }

    catch (const exception& e) {
        cerr << "Error! " << e.what() << endl;
        return 1;
    }
}
