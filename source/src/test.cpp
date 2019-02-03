#include <iostream>
#include "TableReader.hpp"

int main(int argc, char** argv){

    TableReader table("../table3.txt");

    std::cout << table.DescriptionColumn << std::endl;
    std::cout << table.contents.at(5).at(0) << std::endl;




    return 0;
}
