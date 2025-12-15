#include <iostream>
#include <stack>
#include <queue>

int main(){
    std::stack<int> s;
    std::queue<int> q;
    q.push(4);
    q.push(8);
    q.push(15);
    q.push(16);
    q.push(42);
    while(not q.empty()){
        
        int x = q.front();
        q.pop();
        if(x % 2 == 0){
            s.push(x);
        }
    }
    while(not s.empty()){
        int x = s.top();
        s.pop();
        std::cout<< x <<" ";
    }
    std::cout << "\n";
    return 0;
}