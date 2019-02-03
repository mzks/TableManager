#include "TableReader.hh"

TableReader::TableReader(){
};

TableReader::TableReader(TString in){
    InputFilename = in;
};

TableReader::~TableReader(){
    ifs.close();
};

bool TableReader::Read(){

    ifs = std::ifstream(InputFilename);
    if(!ifs) return false;

    std::string str;
    while(getline(ifs, str)){
        // Comments
        if('#' == str.c_str()[0]) continue;

        std::stringstream ss(str);
        std::string item;
        std::vector<std::string> elems;
        while (getline(ss, item, ' ')) {
            if (!item.empty()) {
                elems.push_back(item);
            }
        }

        // Column description
        if('%' == str.c_str()[0]){
            DescriptionColumn = str;
            for(int i=2;i<elems.size();++i){
                ColName.insert(std::make_pair(elems.at(i),i-1));
            }
            continue;
        }

        // Table contents
        std::vector<double> tmpvec;
        for(int i=1;i<elems.size();++i){
            tmpvec.push_back(std::stod(elems.at(i)));
        }

        contents.insert(std::make_pair(std::stoi(elems.at(0)), tmpvec));

    }
    return true;
}
