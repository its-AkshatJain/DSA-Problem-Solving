#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Storig count in map
string FirstNonRepeating(string A){
    unordered_map<char,int> count;
    queue<int> q;
    string ans = "";
    
    for(size_t i=0; i<A.length(); i++){
        char ch = A[i];
        
        count[ch]++;
        
        q.push(ch);
        
        while(!q.empty()){
            if(count[q.front()] > 1){  // repeating
                q.pop();
            }else{  // non repeating
                ans.push_back(q.front());
                break;
            }
        }
        
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

// Storig count in array
string FirstNonRepeating2(string A){
    int count[26] = {0};
    queue<int> q;
    string ans = "";
    
    for(size_t i=0; i<A.length(); i++){
        char ch = A[i];
        
        int index = ch - 'a';
        count[index]++;
        
        q.push(ch);
        
        while(!q.empty()){
            if(count[q.front() - 'a'] > 1){  // repeating
                q.pop();
            }else{  // non repeating
                ans.push_back(q.front());
                break;
            }
        }
        
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
    string s = "aabc";
    cout<<"First non-repeating character in a stream : "<<FirstNonRepeating2(s)<<endl;
}