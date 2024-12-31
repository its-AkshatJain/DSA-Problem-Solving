#include <iostream>
using namespace std;

string removeOccurrences(string s, string part) {
    while(s.length() != 0 && s.find(part)<s.length()){
        s.erase(s.find(part),part.length());
    }
    return s;
}

int main(){
    string s = "daabcbaabcbc";
    string p = "abc";
    string ans = removeOccurrences(s,p);
    cout<<ans<<endl;
}