#include "TableReader.hh"

TableReader::TableReader(){
    AlreadyRead = false;
    DescriptionColumn = "";
};

TableReader::TableReader(TString in){
    AlreadyRead = false;
    InputFilename = in;
    DescriptionColumn = "";
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

    if(true){
       for(int i=0; i<contents.begin()->second.size();++i){
           ColNames.insert(std::make_pair(Form("col%02d",i), i));
       }
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

double TableReader::Get(std::string ColName, int index){
    return this->contents.at(index).at(this->ColNames.at(ColName)) ;
}

double TableReader::Get(int index, std::string ColName){
    return this->contents.at(index).at(this->ColNames.at(ColName)) ;
}
