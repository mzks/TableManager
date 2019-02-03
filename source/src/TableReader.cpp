#include "TableReader.hpp"

TableReader::TableReader(TString in){
    InputFilename = in;
    ifs = std::ifstream(InputFilename);

    this->Read();
};

TableReader::~TableReader(){
};

void TableReader::Read(){

    std::string str;
    while(getline(ifs, str)){
        if('#' == str.c_str()[0]) continue;
        if('%' == str.c_str()[0]){
            DescriptionColumn = str;
            continue;
        }

        std::stringstream ss(str);
        std::string item;
        std::vector<std::string> elems;
        while (getline(ss, item, ' ')) {
            if (!item.empty()) {
                elems.push_back(item);
            }
        }
        std::vector<double> tmpvec;
        for(int i=1;i<elems.size();++i){
            tmpvec.push_back(std::stod(elems.at(i)));
        }

        contents.insert(std::make_pair(std::stoi(elems.at(0)), tmpvec));

    }
}
