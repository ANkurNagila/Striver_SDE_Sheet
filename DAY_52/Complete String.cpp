class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    Trie() { 
        root = new TrieNode('\0'); 
        root->isTerminal=true;
    }

    void insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    void insertWord(string word) { 
        insertWord(root, word); 
    }

    bool help(TrieNode *root,string word){
        if(word.size()==0){
            return root->isTerminal;
        }
        
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL && root->isTerminal==true)
            child=root->children[index];
        else
            return false;
        
        return help(child,word.substr(1));
        
    }
    
    bool search(string word) {
        return help(root,word);
    }
};

string completeString(int n, vector<string> &a){
    string ans="";
    
    Trie head;
    for(int i=0;i<n;i++){
        head.insertWord(a[i]);
    }
    
    
    for(int i=0;i<n;i++){
        if(a[i].size()>ans.size()){
            if(head.search(a[i])==true)
                ans=a[i];
        }
        else if(a[i].size()==ans.size()){
            if(head.search(a[i])==true && a[i]<ans)
                ans=a[i];
        }
        //cout<<ans<<endl;
    }
    
    if(ans=="")
        return "None";
    return ans;
}
