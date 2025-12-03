#include<iostream>
#include<deque>
#include<vector>
#include<stack>

int main(){
    std::vector<int> v = {1,2,4,6,5,88,12,33};
    std::deque d;
    std::stack s;
    
    for(int x:v){
        s.push(x);
    }

    while(not s.empty()){
        int x = s.top();
        s.pop();
        if(x % 2 == 0){
            d.push_front(x*2-1);
        }else{
            d.push_back(-x+1);
        }
    }
    while(not d.empty()){
        int x = d.front();
        d.pop_front();
        std::cout<< x <<", ";
    }
}