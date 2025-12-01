#pragma once
#include <sstream>
#include <stdexcept>

template <typename  T>

class Linkedlist{
    public:
    Linkedlist(const Linkedlist& other) = delete;

    Linkedlist<T>& operator=(const Linkedlist& other) = delete;

    Linkedlist(){
        _sentinel = new Node;
        _sentinel->next = _sentinel;
        _sentinel->prev = _sentinel;
    }

    Linkedlist(std::initializer_list<T> args){
        for(T arg : args){
            insert_back(arg);
        }
    }

    ~Linkedlist(){
        Node* p = _sentinel->next;
        while(p != _sentinel){
            Node* q = p;
            p = p->next;
            delete q;
        }
    }

    bool contains(T value){
        Node* p = _sentinel->next;
        int i = 0;
        while (i != _size-1){
            i++;
            if(p->value == value){
                return true;
            }
            return false;
        }
    }
    void extend(const Linkedlist<T>& other){
        Node* p_other = other._sentinel->next;
        while(p_other != other._sentinel){
            this->insert_back(other.p->value);
            p_other = p_other->next;
        }

    }

    T get(int index)const{
        Node* p = _sentinel->next;
        T result = p->value;
        int i = 0;
        while(i != index){
            i++;
            p = p->next;
        }
        return result;
    }

    void insert_at(int index, T value){
        Node* p = value;
        if (index > _size or index < 0){
            std::out_of_range("The index is out of range, put a valid index")
        } 

        if (index == 0){
            p->value = value;
            p->next = _sentinel->next;
            p->prev = _sentinel;
            _sentinel->next->prev = p;
            _sentinel->next = p;
            _size ++;
        }

        if (index == _size){
            p->value = value;
            p->next = _sentinel;
            p->prev = _sentinel->prev;
            _sentinel->prev->next = p;
            _sentinel->prev = p;
            _size ++;
        }
        int i = 0;
        while (i != index){
            p = _sentinel->next;
            i++;
        }
        p->value = value;
        p->next->prev = p;
        p->prev->next = p;
        size++;
        
    }

    void insert_front(T value){
        Node* p = value;
        p->value = value;
        p->next = _sentinel->next;
        p->prev = _sentinel;
        _sentinel->next->prev = p;
        _sentinel->next = p;
        _size ++;
    }
    void insert_back(T value){
        Node* p = value;
        p->value = value;
        p->next = _sentinel;
        p->prev = _sentinel->prev;
        _sentinel->prev->next = p;
        _sentinel->prev = p;
        _size++;
    }

    bool is_empty(){
        return not _size;
    }

    T remove_at(int index){
        Node* p = _sentinel->next;
        T result = p->value;

        if(index > _size or index < 0){
            std::out_of_range("The insert a valid index");
        }

        if (index = _size-1){
        _sentinel->prev = p->prev;
        p->prev->next = _sentinel;
        delete p;
        _size--;
        }

        if(index == 0){
        _sentinel->next = p->next;
        p->next->prev = _sentinel;
        delete p;
        _size--;
        }

        int i = 0;
        while(i != index-1){
            p = p->next;
            i++;
        }
        p->next->prev = p->next;
        p->prev->next = p->prev;
        delete p;
        _size--;
        return result;
    }
    
    T remove_front(){
        if(is_empty()){
            throw std::length_error("Cant remove front of empty list");
        }
        Node* p = _sentinel->next;
        T result = p->value;
        _sentinel->next = p->next;
        p->next->prev = _sentinel;
        delete p;
        _size--;
        return result;

    }

    T remove_back(){
        if(is_empty()){
            throw std::length_error("Cant remove front of empty list");
        }
        Node* p = _sentinel->prev;
        T result = p->value;
        _sentinel->prev = p->prev;
        p->prev->next = _sentinel;
        delete p;
        _size--;
        return result;
    }
    int size()const{
        return _size;
    }

    std::string to_string()const{
        std::ostringstream result;
        result<<"[";
        bool first_time = true;
        Node* p = _sentinel->next;
        while(p != _sentinel){
            if(first_time){
                first_time = false;
            }else{
                result<< p->value;
                p = p->next;
            }
            result <<"]";
            return result.str();
        }
    }

    private: 
    struct Node {
        T value;
        Node* next;
        Node* prev;
    };
    Node* _sentinel = nullptr;
    int _size = 0;

};