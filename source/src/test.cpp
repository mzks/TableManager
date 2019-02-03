#include <iostream>
#include "TableReader.hpp"

int main(int argc, char** argv){

    TableReader table("./table2.txt",3);

    std::cout << table.contents.at(1).at(0) << std::endl;
    std::cout << table.contents.at(2).at(0) << std::endl;
    std::cout << table.contents.at(3).at(0) << std::endl;
    std::cout << table.contents.at(4).at(1) << std::endl;
    std::cout << table.contents.at(5).at(0) << std::endl;
    std::cout << table.contents.at(6).at(1) << std::endl;




    return 0;
}
