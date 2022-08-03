#include<bits/stdc++.h>
class Node{
    public:
    int key,value;
    Node *next,*prev;
    
    Node(){
        key=0;
        value=0;
        next=NULL;
        prev=NULL;
    }
    
    Node(int key,int value){
        this->key=key;
        this->value=value;
        next=NULL;
        prev=NULL;
    }   
};

class LRUCache
{
public:
    int total;
    unordered_map<int,Node*> map;
    Node *head=new Node();
    Node *tail=new Node();
    LRUCache(int capacity)
    {
        total=capacity;
        head->next=tail;
        tail->prev=head;
        
    }

    int get(int key)
    {
        if(map.find(key)!=map.end()){
            Node *temp1=map[key]->prev;
            Node *temp2=map[key]->next;
            int value=map[key]->value;
            
            temp1->next=temp2;
            temp2->prev=temp1;
            
            Node *one =new Node(key,value);
            Node *temp=head->next;
            head->next=one;
            one->prev=head;
            temp->prev=one;
            one->next=temp;
            
            map[key]=one;
            return value;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        if(map.find(key)!=map.end()){
            Node *temp1=map[key]->prev;
            Node *temp2=map[key]->next;
            
            temp1->next=temp2;
            temp2->prev=temp1;
            
            Node *one =new Node(key,value);
            Node *temp=head->next;
            head->next=one;
            one->prev=head;
            temp->prev=one;
            one->next=temp;
            
            map[key]=one;
            return ;
        }
        
        
        if(map.size()<total){
            Node *one =new Node(key,value);
            Node *temp=head->next;
            head->next=one;
            one->prev=head;
            temp->prev=one;
            one->next=temp;
            
            map[key]=one;
        }
        else{
            Node *temp1=tail->prev;
            map.erase(temp1->key);
            temp1=temp1->prev;
            temp1->next=tail;
            tail->prev=temp1;
            
            Node *one =new Node(key,value);
            Node *temp=head->next;
            head->next=one;
            one->prev=head;
            temp->prev=one;
            one->next=temp;
            
            map[key]=one;
        }
    }
};
