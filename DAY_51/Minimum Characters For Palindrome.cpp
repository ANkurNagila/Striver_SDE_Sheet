#include<bits/stdc++.h>

bool isPalind(string& str, int start, int end){
    while(start<end){
        if(str[start] != str[end]){
            return false;
        }
        start++; end--;
    }
    return true;
}

int minCharsforPalindrome(string str) {
    int len = str.size();
    int i=0;
    int j = len-1;
    while(0<j){
        if(isPalind(str, 0, j)){
            return len - j - 1;
        }else{
            j--;
        }
    }
    return len-1;
}
