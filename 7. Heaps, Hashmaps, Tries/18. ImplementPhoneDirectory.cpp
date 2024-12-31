#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        // Base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // Assumption that all letters are capital
        int index = word[0] - 'a';
        TrieNode* child;

        //Present
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            // Absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        for(char ch ='a'; ch<='z'; ch++){
            TrieNode* next = curr->children[ch-'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back(); // backtrack to explore other options
            }
        }
    }

    vector<vector<string>> getSuggestions(string str){
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for(int i=0; i<str.length(); i++){
            char lastch = str[i];
            prefix.push_back(lastch);

            // Check for lastch
            TrieNode* curr = prev->children[lastch-'a'];

            // Not Found
            if(curr == NULL){
                break;
            }

            // Found
            vector<string> temp;
            printSuggestions(curr,  temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    // Create a trie
    Trie* t = new Trie();

    // Insert all the contacts in Tries
    for(int i=0; i<contactList.size(); i++){
        string str = contactList[i];
        t->insertWord(str);
    }

    // return
    return t->getSuggestions(queryStr);
}

int main(){
    vector<string> v;
    v.push_back("coding");
    v.push_back("codezen");
    v.push_back("coding ninjas");
    v.push_back("coders");

    string s = "c";
    vector<vector<string>> ans = phoneDirectory(v, s);
    for(auto suggestionList: ans){
        for(auto word: suggestionList){
            cout<<word<<" ";
        }
    } 
    cout<<endl;
}