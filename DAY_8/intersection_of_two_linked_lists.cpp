#include <bits/stdc++.h> 
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    unordered_set<Node *> x;
    
    while(firstHead!=NULL){
        x.insert(firstHead);
        firstHead=firstHead->next;
    }
    
    while(secondHead!=NULL){
        if(x.find(secondHead)!=x.end())
            return secondHead->data;
        
        secondHead=secondHead->next;
    }
    
    return -1;
    
}
