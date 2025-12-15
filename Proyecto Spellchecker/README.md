# Project Spellchecker  

*Compilation command:*
g++ spellchecker.cpp -o spellchecker

*Running command*
./spellchecker <filename.txt>
    
    *Example:*
    ./spellchecker frankenstein.txt

*Description*
This C++ program is a Spellchecker that analyzes a text file to identify words not found in the dictionary. It utilizes the Soundex algorithm to generate similar suggestions for misspelled words and gets the exact line and column where each error occurs.