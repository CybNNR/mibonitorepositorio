#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
    public: 
    Queue(int capacity): _capacity(capacity + 1), _data(new T[capacity + 1]){
    }

    ~Queue(){
        delete [] _data;
    }

    Queue(const Queue& other) = delete;
    Queue<T>& operator=(const Queue& other) = delete;

    int capacity()const{
        return _capacity - 1;
    }

    void clear(){
        _next = 0;
        _last = 0;
        _size = 0;
    }

    bool is_empty(){
        return (_next == _last);
    }

    void enqueue(const T& value){
        if(_size == _capacity - 1){
            throw std::overflow_error("Overflow, queue is full")
        }

        _data[_next] = value;
        _next = (_next + 1) % _capacity;
        _size++;
    }

    T dequeue(){
        if(is_empty()){
            throw std::underflow_error("Underflow! the queue is empty")
        }
        T result = _data[_last];
        _last = (_last + 1) % _capacity;
        _size--;
        return result;
    }

    T peek(){
        if(is_empty()){
            throw std::underflow_error("Underflow! the queue is empty")
        }
        T result = _data[_last];
        return result;
    }

    int size(){
        return _size;
    }

    private:
    const int _capacity;
    int _last;
    int _next;
    int _size;
    T* _data;

};