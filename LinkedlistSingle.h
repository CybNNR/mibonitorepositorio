#pragma once

class linkedlist{
    public:
    
    int minimum(Node* list){
        int min_value = list->value;
        list = list->next;
        while (list->next != nullptr){
            if(list->value < min_value){
                min_value = list->value;
            }
            list = list->next;
        }
    return min_value;
    }

    private:

    struct Node{
        int value;
        Node* next;
    }
    
};