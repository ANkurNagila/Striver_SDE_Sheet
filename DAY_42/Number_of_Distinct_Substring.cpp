#include<bits/stdc++.h>
int distinctSubstring(string &word) {
    set<string> x;
    
    for (int i = 0; i < word.length(); i++) {
        string subStr;
        for (int j = i; j < word.length(); j++) {
            subStr += word[j];
            x.insert(subStr);
        }
    }
    
    return x.size();
}
