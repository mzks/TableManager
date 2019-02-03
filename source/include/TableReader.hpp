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

    public:
        TableReader(TString in);
        ~TableReader();
        void Read();
        std::map<int, std::vector<double> > contents;
        TString DescriptionColumn;
};
