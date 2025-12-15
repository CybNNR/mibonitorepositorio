#include <iostream>
#include <map>
#include <vector>

int main(){
    std::map<int, std::vector<int>> m;
    for (int n = 0; n <= 10; n++){
        std::vector<int> v;
        for(int i = 1; i <= n; i++){
            if( n % i == 0){
                v.push_back(i);
            }
        }
        m[n] = v;
    }
    for(auto p : m){
        std::cout<< p.first << ": ";
        for (int x : p.second){
            std::cout << x <<", ";
        }
        std::cout << "\n";

    }
    return 0;
}