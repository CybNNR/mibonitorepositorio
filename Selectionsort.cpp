#include <iostream>
#include <vector>
#include <utility>

template <typename T>

void selectionsort(std::vector<int>& vect){
    for(int i = 0; i < vect.size(); i++){
        int min_index = i;
        for(int j = i + 1; j < vect.size(); j++){
            if(vect.at(j) < vect.at(min_index)){
                min_index = j;
            }
        }
        std::swap(vect.at(i), vect.at(min_index));
    }
}