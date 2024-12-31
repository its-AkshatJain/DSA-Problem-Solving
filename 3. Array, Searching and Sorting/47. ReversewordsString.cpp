#include <iostream>
using namespace std;

void reverse(string &s, int start, int end){
    while(start<end){
        swap(s[start++],s[end--]);
    }
}

//Reverse Words in a string
void reverseWordsInString(string &s){
    int start=0,end=0;
    int n = s.length();
    while(start<n){
        // Move end to the end of the current word
        while(end<n && s[end]!=' '){
            end++;
        }
        //Reversing word
        reverse(s,start,end-1);
        // Move start and end to the next word
        start=end+1;
        end= start;
    }
}

//Reverse order of Words in a string
string reverseWords(string s) {
        int start = 0, end = 0;
        int n = s.length();
        // string ans = "";

        // Reverse entire string
        reverse(s, start, n - 1);

        // Reverse each word
        while (start < n) {
            while (end < n && s[end] != ' ') {
                end++;
            }
            reverse(s, start, end - 1);
            
            // For trimming spaces
            // if(start<n){
            //     if(!ans.empty()){
            //         ans += ' ' + s.substr(start,end-start);
            //     }else{
            //         ans += s.substr(start,end-start);
            //     }
            // }
    
            start = end + 1;
            end = start;
        }
        
        return s;
    }

int main(){
    string s = "My name is Akshat Jain";
    string s1` = " hello  world ";
    cout<<s<<endl;
    // reverseWordsInString(s);
    // cout<<s<<endl;
    string ans = reverseWords(s);
    cout<<ans<<endl;
}