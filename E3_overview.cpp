#include <iostream>
#include <vector>
#include <algorithm>
//Compares numbers in a vector for a sorting in smaller to biggest sort
bool the_comparator(int a, int b){
    return std::abs(a) <= std::abs(b);
}

int main(){
    std::vector<int> numbers = {1,5,4,10,3,343,141}; 
    std::sort(numbers.begin(), numbers.end(), the_comparator);
    for (int x : numbers){
        std::cout<< x << " ";
    }
    std::cout<< "\n";
    return 0;
}