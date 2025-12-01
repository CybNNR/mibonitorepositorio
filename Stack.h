#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>

class Stack {
    private:
    int _capacity;
    int _top;
    T* _data;

    public: 
    Stack(int capacity){
        _capacity = capacity;
        _top = 0;
        _data = new T[_capacity]
    }

    ~Stack(){
        delete [] _data;
    }

    Stack(const Stack& other) = delete;

    Stack<T>& operator=(const Stack& other) = delete;

    int capacity(){
        return _capacity;
    }

    int size(){
        return _top;
    }

    bool is_empty(){
        return not _top;
    }

    void push(T value){
        if(_top == _capacity){
            throw std::exception("Stack overflow!, too many elements in stack");
        }
        _data[_top] = value;
        _top++;
    }

    T pop(){
        if(is_empty()){
            throw std::exception("Stack underflow no elements in stack");
        }
        _top--;
        return _data[_top];
    }

    void clear(){
        _top = 0;
    }

    T peek(){
        if(is_empty()){
            throw std::exception("The array is empty, no elements are in it");
        }
    T value = _data[_top - 1];
    return value;
    }


};