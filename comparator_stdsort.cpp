// comparador de palabras de mayor a menor: 

#include <algorithm>
#include <iostream>
#include <vector>

bool the_comparator(std::string a, std::string b){
    if (a.size() != b.size()){
        return a.size() > b.size();
    }
    return a < b; // si los elementos encontrados en la lista son del mismo tamaño , entonces retornamos el elemento en orden alfabetico
}

int main(){
    std::vector<std::string> names { Daniel, David,Cristian, Carlos, Ricardo, Lesly, Jorge, Manuel, };
    std::sort(names.begin(), names.end(), &the_comparator);
    for (std::string name : names){
        std::cout << name << " ";
    }
    return 0;
}