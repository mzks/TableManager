///
/// @file TableReader.hpp
/// @brief Reader for ASCII table
/// @author Keita Mizukoshi
/// @date   2019 02 03
///

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <TString.h>

///
/// @class TableReader
/// @brief ASCII table reader for CANDLES analysis

// -//-------------------------
// # table example
// # Analyzer C. A. DLES
// # Date: 2100. Jan. 01
// % Crystal  X     Y     Z
//    1       100.  200.  300. 
//    2       110.  210.  310. 
//    3       120.  220.  320. 
//    4       130.  230.  330. 
//    5       140.  240.  340. 
//    6       150.  250.  350. 
// //--------------------------
// Using this class, you can ignore comment sentences which
// start at '#'.
// The sentence which starts at '%' is special one for
// adding column names for this class.
// You can access value using comumn name.
// The initial column requires to be integer.
// Others will be casted to double.
// 
class TableReader{
    private:
        std::ifstream ifs;

        /// @brief requires to read once
        bool AlreadyRead;

    public:
        /// @brief table file name
        /// @details set in constructor or manually
        TString InputFilename;

        /// @brief Constructor
        TableReader();

        /// @brief Constructor
        /// @param[in] in input filename of tables
        TableReader(TString in);

        ~TableReader();

        /// @brief Read table
        /// @details This function reads the table actually.
        /// Set contents, ColName, and DescriptionColumn.
        /// @return bool If the file reading is succeeded, return true.
        bool Read();

        /// Contener of table, its 1st columns are keys.
        std::map<int, std::vector<double> > contents;

        /// Get column number by name
        std::map<std::string, int> ColNames;

        /// Comment in table using %
        TString DescriptionColumn;

        /// Output all table contents for debug
        void OutputAll();

        /// Get Parameter using column name
        double Get (std::string ColName, int index);
        double Get (int index, std::string ColName);


};
