# TableReader

ASCII table reader for CANDLES analysis.

Here, You have a table described below,
```
# table example
# Analyzer C. A. DLES
# Date: 2100. Jan. 01
% Crystal  X     Y     Z
   1       100.  200.  300. 
   2       110.  210.  310. 
   3       120.  220.  320. 
   4       130.  230.  330. 
   5       140.  240.  340. 
   6       150.  250.  350. 
```
Using this class, you can ignore comment sentences which
start at '#'.
The sentence which starts at '%' is special one for adding
column names for this class.
You can access value using comumn name.
Initial column requires to be integer.
Others casted to double.

First, set input filename in this constructor or `InputFilename` manually.
Then, call `Load()` function.
```
TableReader table("./example.txt");
if(!table.Load()){
\\failure
 return 1;
 }
```

You can access the contents by
```
double val1 = table.contents.at(1).at(0);
//100.0
double val2 = table.Read("X",2);
//110.0
double val3 = table.Read(3, "col02");
//320.0
```
