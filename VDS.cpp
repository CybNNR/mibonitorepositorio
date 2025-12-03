#include <iostream>
#include <deque>
#include <vector>
#include <stack>

int main(){
    std::vector<int> V = {4, 8, 15, 16, 23, 42};
    std::deque<int> D; 
    std::stack<int> S;

    for(int x : V){
        std::cout<< x << "\n";
        S.push(x);
    }

    while(not S.empty()){
        int x = S.top();
        std::cout<< x << "\n";

        S.pop();
        if(x % 2 == 0){
            D.push_front(x*2-1);
        }
        else{
            D.push_back(-x+1);
        }
        
    }

    while (not D.empty()){
        int x = D.front();
        std::cout<< x <<"\n"; 

        D.pop_front();
        // std::cout<< x <<"\n"; 
    }
 };