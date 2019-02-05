#include <utility>
#include "TableReader.hh"

TableReader::TableReader(){
    AlreadyRead = false;
};

TableReader::TableReader(TString in){
    AlreadyRead = false;
    InputFilename = in;
};

bool TableReader::Load(){

    ifs = std::ifstream(InputFilename);
    if(!ifs) return false;

    if(AlreadyRead) return false;

    AlreadyRead = true;
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
            for(auto i=2;i<elems.size();++i){
                ColNames.insert(std::make_pair(elems.at(i),i-2));
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

    for(int i=0; i<contents.begin()->second.size();++i){
        ColNames.insert(std::make_pair(Form("col%02d",i), i));
    }
    return true;
}

void TableReader::OutputAll(){
    std::cout << InputFilename << std::endl;
    std::cout << DescriptionColumn << std::endl;
    for (auto &content : contents) {
        std::cout << content.first << "  ";
        for (double i : content.second) {
            std::cout << i << "  ";
        }
        std::cout << std::endl;
    }
}

double TableReader::Read(std::string ColName, unsigned int index){
    return this->contents.at(index).at(ColNames.at(ColName)) ;
}

double TableReader::Read(unsigned int index, std::string ColName){
    return this->contents.at(index).at(ColNames.at(ColName)) ;
}
