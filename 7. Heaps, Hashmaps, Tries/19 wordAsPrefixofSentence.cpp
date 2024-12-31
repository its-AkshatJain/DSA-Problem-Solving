class Solution {
struct trienode{
    int idx; 
    unordered_map<char, trienode*> child;
};
trienode* root = new trienode;

void trieInsertWord(string word, int index){
    trienode* curr = root;
    for(int i=0; i<word.length(); i++){
        if(!curr->child.count(word[i])){  // checks if curr node has word[i] child present or not and if not present create a child
            curr->child[word[i]] = new trienode;
            curr->child[word[i]]->idx = index;
        }
        curr = curr->child[word[i]];
    }
}

int trieSearchWord(string word){
    trienode* curr = root;
    for(int i=0; i<word.length(); i++){
        if(!curr->child.count(word[i])){  
           return -1;
        }
        curr = curr->child[word[i]];
    }
    return curr->idx;
}
public:
int isPrefixOfWord(string sentence, string searchWord) {
    int n = sentence.size();
    int index= 1;

    for(int i=0; i<n; i++){
        string word = "";
        while(i<n && sentence[i]!=' '){
            word.push_back(sentence[i]);
            i++;
        }
        trieInsertWord(word, index);
        index++;
    }
    return trieSearchWord(searchWord);
}
};