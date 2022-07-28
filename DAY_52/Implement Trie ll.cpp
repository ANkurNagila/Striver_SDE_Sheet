class TrieNode{
    public:
    char data;
    TrieNode **children;
    int c_word;
    int c_prefix;
    
    TrieNode(char data){
        this->data=data;
        children=new TrieNode *[26];
        for(int i=0;i<26;i++)
            this->children[i]=NULL;
        
        this->c_word=0;
        this->c_prefix=0;
    }
};

class Trie{
    public:
        TrieNode *root;
    Trie(){
        root=new TrieNode('\0');
    }
    
    void insert(TrieNode *root,string word){
        if(word.size()==0){
            root->c_word+=1;
            root->c_prefix+=1;
            return ;
        }
        
        int index=word[0]-'a';
        TrieNode *child;
        
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        
        root->c_prefix+=1;
        
        insert(child,word.substr(1));
    }
    
    
    void insert(string &word){
        insert(root,word);
    }
    
    int countWordsEqualTo(TrieNode *root,string word){
        if(word.size()==0){
            return root->c_word;
        }
        
        int index=word[0]-'a';
        TrieNode *child;
        
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return 0;
        }
         
        return countWordsEqualTo(child,word.substr(1));
    }
    
    int countWordsEqualTo(string &word){
        return countWordsEqualTo(root,word);
    }
    
    int  countWordsStartingWith(TrieNode* root,string word){
        if(word.size()==0){
            return root->c_prefix;
        }
        
        int index=word[0]-'a';
        TrieNode *child;
        
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return 0;
        }
         
        return countWordsStartingWith(child,word.substr(1));
    }
    
    int countWordsStartingWith(string &word){
        return countWordsStartingWith(root,word);
    }
    
    
    bool help(TrieNode *root,string word){
        if(word.size()==0){
            return root->c_word>0;
        }
        
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL)
            child=root->children[index];
        else
            return false;
        
        return help(child,word.substr(1));
        
    }
    
    bool search(string word) {
        return help(root,word);
    }

    void erase(TrieNode *root,string word){
        if(word.size()==0){
            root->c_word-=1;
            root->c_prefix-=1;
            return ;
        }
        
        int index=word[0]-'a';
        TrieNode *child;
        
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return ;
        }
        
        root->c_prefix-=1;
        
        erase(child,word.substr(1));
    }
    
    void erase(string &word){
        if(search(word))
            erase(root,word);
        return ;
    }
};
