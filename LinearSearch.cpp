#include <iostream>
#include <vector>

int linearsearch(std::vector<int>& vect, int x){
    for(int i = 0; i < vect.size(); i++){
        if(vect[i] == x){
            return i;
        }
        return -1;
    }
}
