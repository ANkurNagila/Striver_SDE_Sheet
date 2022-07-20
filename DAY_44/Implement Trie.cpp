/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
class Node{
    public:
        char data;
        Node **children;
        bool is_end;
    
    Node(char ele){
        this->data=ele;
        children=new Node *[26];
        for(int i=0;i<26;i++)
            children[i]=NULL;
        
        is_end=false;
    }
};

class Trie {

public:
    Node *root;
    /** Initialize your data structure here. */
    Trie() {
        root=new Node('\0');
    }

    void help(string word,Node *root){
        if(word.size()==0){
            root->is_end=true;
            return ;
        }
        
        int index=word[0]-'a';
        Node *child;
        if(root->children[index]!=NULL)
            child=root->children[index];
        else{
            child=new Node(word[0]);
            root->children[index]=child;
        }
        
        help(word.substr(1),child);
        
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        help(word,root);
    }

    bool help2(Node *root,string word){
        if(word.size()==0){
            return root->is_end;
        }
        
        int index=word[0]-'a';
        if(root->children[index]==NULL)
            return false;
        
        Node *child=root->children[index];
        return help2(child,word.substr(1));
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return help2(root,word);
    }

    bool help3(Node *root,string word){
        if(word.size()==0){
            return true;
        }
        
        int index=word[0]-'a';
        if(root->children[index]==NULL)
            return false;
        
        Node *child=root->children[index];
        return help3(child,word.substr(1));
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return help3(root,prefix);
    }
};
