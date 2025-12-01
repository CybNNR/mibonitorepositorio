#pragma once

class singlelinkedlist{
    public:
    void reverse(Node*& list){
        if(list == nullptr){
            return;
        }

        Node* before = nullptr;
        Node* after = list->next;
        while(after != nullptr){
            list->next = before;
            before = list;
            list = after;
            after = after->next;
        }
        list->next = before;
    }

    private: 
    struct Node{
        int value;
        Node* next;
    };
    
};