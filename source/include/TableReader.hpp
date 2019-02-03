#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <TString.h>

class TableReader{
    private:
        TString InputFilename;
        std::ifstream ifs;
        int NumOfColumn;

    public:
        TableReader(TString in, int Column);
        ~TableReader();
        void Read();
        std::map<int, std::vector<double> > contents;
};
