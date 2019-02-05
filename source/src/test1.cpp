#include <iostream>
#include "TableReader.hh"

int main(int argc, char** argv){


    TableReader table("../table3.txt");
    if(!table.Load()){
        table.InputFilename = "./table.txt";
        table.Load();
    }

    //std::cout << table.DescriptionColumn << std::endl;
    //std::cout << table.contents.at(5).at(0) << std::endl;
    //std::cout << table.contents.at(5).at(table.ColName.at("energy")) << std::endl;

    std::cout << table.Read("energy",5) << std::endl;
    std::cout << table.Read(4, "energy") << std::endl;

    table.OutputAll();

    return 0;
}
