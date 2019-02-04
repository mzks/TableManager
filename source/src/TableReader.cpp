#include "TableReader.hh"

TableReader::TableReader(){
    AlreadyRead = false;
};

TableReader::TableReader(TString in){
    AlreadyRead = false;
    InputFilename = in;
};

TableReader::~TableReader(){
    ifs.close();
};

bool TableReader::Read(){

    ifs = std::ifstream(InputFilename);
    if(!ifs) return false;

    if(AlreadyRead == true) return false;

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

void TableReader::OutputAll(){

    std::cout << InputFilename << std::endl;
    std::cout << DescriptionColumn << std::endl;

    for(auto itr = contents.begin(); itr != contents.end(); ++itr) {
        std::cout << itr->first << "  ";
        for(int i=0;i<itr->second.size();++i){
            std::cout << itr->second.at(i) << "  ";
        }
        std::cout << std::endl;
    }
    
}
