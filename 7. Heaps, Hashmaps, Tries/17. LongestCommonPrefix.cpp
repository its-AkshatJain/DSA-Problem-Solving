#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";

    // for traversing each character of first string
    for(int i=0; i<arr[0].length(); i++){
        char ch = arr[0][i];

        bool match = true;

        // for traversing remaining string
        for(int j=1; j<n; j++){
            // Not match
            if(arr[j].length() < i || ch != arr[j][i]){
                match = false;
                break;
            }
        }
        if(match == false){
            break;
        }else{
            ans.push_back(ch);
        }
    }
    return ans;
}

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount; 

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie{
    public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // Present
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            // Absent
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    void lcp(string str, string &ans){
        for(int i=0; i<str.length(); i++){
            char ch = str[i];

        if(root->childCount == 1){
            ans.push_back(ch);
            // Aage badhao
            int index = ch - 'a';
            root = root->children[index];
        }else{
            break;
        }

        if(root->isTerminal){
            break;
        }
        }
    }
};


// Using trie
string longestCommonPrefix2(vector<string> &arr, int n)
{
    string ans = "";
    Trie* t = new Trie();

    // Insert all string in Trie
    for(int i=0; i<n; i++){
        t->insertWord(arr[i]);
    }

    string first = arr[0];

    t->lcp(first, ans);
    return ans;
}

int main(){
    vector<string> v;
    v.push_back("coding");
    v.push_back("codezen");
    v.push_back("coding ninjas");
    v.push_back("coders");

    cout<<"Longest common Prefix : "<<longestCommonPrefix(v,4)<<endl;

    cout<<"Longest common Prefix (Using Trie) : "<<longestCommonPrefix2(v,4)<<endl;
}