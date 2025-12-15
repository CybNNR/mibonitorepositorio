#include <iostream>

int f(int n){
    int r = 1;
    for (int i = 0; i < n; i++){
        r *= 2;
    }
    return r;
}

void G(int n){
    int r = f(n);
    for (int i = 0; i < r; i++){
        std::cout<< i <<" ";
    }
    std::cout<<"\n";
}

int main(){
    int Num = 1;
    int Num2 = 2;
    int Num3 = 3;
    int Num4 = 10;
    G(Num);
    G(Num2);
    G(Num3);
    G(Num4);
    return 0;
}