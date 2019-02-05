#include <iostream>
#include "TableReader.hh"

int main(int argc, char** argv){


    TableReader table("../table3.txt");
    if(!table.Read()){
        table.InputFilename = "./table.txt";
        table.Read();
    }

    //std::cout << table.DescriptionColumn << std::endl;
    //std::cout << table.contents.at(5).at(0) << std::endl;
    //std::cout << table.contents.at(5).at(table.ColName.at("energy")) << std::endl;

    //std::cout << table.Get("energy",5) << std::endl;
    //std::cout << table.Get(4, "energy") << std::endl;

    std::cout << table.Get(1, "col00") << std::endl;
    std::cout << table.Get(1, "col01") << std::endl;
    std::cout << table.Get(1, "energy") << std::endl;


    table.OutputAll();

    return 0;
}
