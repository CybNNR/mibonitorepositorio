#include <iostream>
#include <vector>

int binarysearch(std::vector<int>& vect, int value){
    int min = 0;
    int max = vect.size() - 1;
    while(min <= max){
        int mid = min + (max - min)/2;
        if(vect[mid] == value){
            return mid;
        }
        if(vect[mid] < value){
            min = mid + 1;
        }
        else{
            min = mid - 1;
        }
    }
    return -1; 
}