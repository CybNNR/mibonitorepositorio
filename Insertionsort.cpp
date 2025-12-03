#include <iostream>
#include <vector>
void insertionsort(std::vector<int>& vect){
    int n = vect.size();
    for(int i = 1; i < n; i++){
        int value = vect.at(i);
        int j = i - 1;
        while(j >= 0 and vect[j] > value){
            std::swap(vect.at(j), vect.at(j+1));
            j = j - 1;
        }
    }
}

void printarray(std::vector<int>& vect){
    int n = vect.size();
    for(int i = 0; i <  n; i++){
        std::cout<< vect[i] << " \n";
    }
}

int main(){
    std::vector<int> a = {1,2,5,6,3,4,7,9,8};
    printarray(a);
    insertionsort(a);
    printarray(a);
}