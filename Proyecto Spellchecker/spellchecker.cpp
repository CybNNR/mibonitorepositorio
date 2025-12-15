/*----------------------------------------------------------
 * Project: Spell Checker
 *
 * Date: 03-Dec-2025
 * Authors:
 *           A01803173 José Manuel Bañuelos Silva
 *           A01802469 Juan Manuel Sánchez Velázquez
 *           A01753587 David Elías Vargas Ayala
 *----------------------------------------------------------*/
#include <fstream>
#include <chrono>
#include <regex>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
// Global variables:
struct word {
    std::string text;
    int line;
    int column;
};
std::unordered_map<char, char> soundexMap = {
    {'b', '1'}, {'f', '1'}, {'p', '1'}, {'v', '1'},
    {'c', '2'}, {'g', '2'}, {'j', '2'}, {'k', '2'}, {'q', '2'}, {'s', '2'}, {'x', '2'}, {'z', '2'},
    {'d', '3'}, {'t', '3'},
    {'l', '4'},
    {'m', '5'}, {'n', '5'},
    {'r', '6'}
}; // Contenedor de palabras no encontradas
std::unordered_set<char> dropChar = {'a', 'e', 'i', 'o', 'u', 'h', 'w', 'y'};
std::unordered_set<std::string> dictionary; 
std::unordered_map<std::string,std::vector<std::string>> soundexDictionary;
std::string dictionaryName = "words.txt";
std::vector<word> words; 
std::vector<word> notFoundWords;

// Functions:

/*To convert the characters to lower it crosses all the letters in word using the c++ standard libray function std::to_lower*/
std::string to_lower(std::string word){
    for(char& letter : word){ 
        letter = std::tolower(letter);
    }
    return word;
}

/* The encode_word function uses the function encode_word, leaving the first letter on uppercase,
then it deletes the characters that coincide contained in the dropchar unordered_set, finally it adjusts size of the word 
to be 7 letters long */ 
std::string encode_word(std::string w){
    w=to_lower(w);
    w[0]=std::toupper(static_cast<char>(w[0]));
    int i = 1;
    while(i < w.size()){
        if(dropChar.count(w[i])){ 
            w.erase(i, 1);
            i--;
        }
        else w[i] = soundexMap.at(w[i]);
        i++;
    }
    while(w.size() < 7){
        w += '0';
    }
    while(w.size() > 7){
        w.pop_back();
    }
    return w;
}

/* The function print_words_found recives a vector wich contains all the words on a text, then it prints them by the word, line and
 column where it was found */
void print_words_found(const std::vector<word>& words){
    for (word w : words) {
        std::cout << w.text << "  (line " << w.line
            << ", column " << w.column << ")\n";
    }
}

/* The encoded_dictionary_build recieves the non-encoded dictionary and for every word on it,
it encodes them and saves it on the map */
void encoded_dictionary_build(const std::unordered_set<std::string>& dictionary2Encode, std::unordered_map<std::string,std::vector<std::string>>& dictionaryEncoded){
    for(const std::string& word2Encode : dictionary2Encode){
        std::string wordEncoded=encode_word(word2Encode);
        dictionaryEncoded[wordEncoded].push_back(word2Encode);
    }
};

/* Provided by professor */
bool dictionary_build(std::string dictionaryName){
    std::ifstream inputDictionary(dictionaryName);
    if(inputDictionary.fail()) return false;
    std::regex reg_exp("[a-zA-Z]+");
    std::smatch match;
    std::string text;
    int line = 0;
    int column = 0;
    while (std::getline(inputDictionary, text)) {
        ++line;
        column = 1;
        while (std::regex_search(text, match, reg_exp)) {
            column += match.position();
            dictionary.insert(match.str());
            column += match.length();;
            text = match.suffix().str();
        }
    }
    encoded_dictionary_build(dictionary,soundexDictionary);
    return true;
}

/* Provided by professor */
bool read_words(const std::string& input_file_name, std::vector<word>& words){
    std::ifstream input_file(input_file_name);
    if (input_file.fail()) {
        return false;
    }
    std::regex reg_exp("[a-zA-Z]+");
    std::smatch match;
    std::string text;
    int line = 0;
    int column = 0;
    while (std::getline(input_file, text)) {
        ++line;
        column = 1;
        while (std::regex_search(text, match, reg_exp)) {
            column += match.position();
            words.push_back({match.str(), line, column});
            column += match.length();
            text = match.suffix().str();
        }
    }
    return true;
}

/* The function print_suggestions recives a vector of suggestions and prints all available suggestions */
void print_suggestions(const std::vector<std::string>& suggestions){
    bool firstTime=true;
    for(const std::string& suggest : suggestions){
        if(firstTime){
            std::cout<<"Suggestions: "<<suggest;
            firstTime=false;
        }
        else std::cout<<", "<<suggest;
    }
    std::cout<<"\n";

}

    bool firstTime=true;
/* The main function works by reciving one file, wich will be the text used to find the words, it builds the dictionary converts the words in

 */
int main(int argc, char* argv[]){
    auto start = std::chrono::high_resolution_clock::now();
    std::string fileName;
    // Launch message of missing filename to read in running command
    if(argc < 2){
        std::cout<<"\n\n\tText filename to read missing!\n\n";
        return 1;
    }else{
        fileName = argv[1];
    }
    // Throws an exception if there's a fail building the dictionary
    if(!dictionary_build(dictionaryName)) throw std::ios_base::failure("\n\n\tUnable to find dictionary file!\n\n");
    // Throws an exception if there's a fail reading the words from file entered
    if(!read_words(fileName, words)) throw std::ios_base::failure("\n\n\tUnable to find file to read!\n\n");
    // Checks spelling from file comparing with dictionary
    for(int i = 0; i < words.size(); i++){
        bool flag=true;
        std::string wordToFind = to_lower(words[i].text);
        if(dictionary.count(wordToFind)){
            continue; //If word is not misspelled, skip 
        }
        else{
            // Checks if word was already found 
            for(const word& notFoundWord : notFoundWords){
                if(to_lower(notFoundWord.text)==wordToFind) {
                    flag=false;
                    break;
                }
            }
            // If word is misspelled and is not repeated, appends it to notFoundWords vector
            if(flag) notFoundWords.push_back(words[i]);
        }
    }
    // Finds suggestions for misspelled words and print them
    for(const word& notFoundWord : notFoundWords){
        bool firstTime = true;
        std::string notFoundWordEncoded = encode_word(notFoundWord.text);
        auto suggestCode = soundexDictionary.find(notFoundWordEncoded);
        std::cout<<"\nUnrecognized word: \""<< notFoundWord.text <<"\". First found at line " 
                 << notFoundWord.line << ", column " << notFoundWord.column << ".\n";
        if(suggestCode==soundexDictionary.end()){
            std::cout<<"No suggestions.\n";
        }else{
            std::sort(suggestCode->second.begin(),suggestCode->second.end());
            print_suggestions(suggestCode->second);
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    double total_time = duration.count() / 1'000'000.0;
    
    // Uncomment to see total runtime
     std::cout<<"\n\n\n\t\tTotal Runtime: "<<total_time<<"\n\n";
}