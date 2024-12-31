#include <iostream>
using namespace std;

string removeDuplicates(string s) {
    string result;
    for(char c: s){
        if(!result.empty() && result.back() == c ){
            result.pop_back();
        }else{
            result.push_back(c);
        }
    }
    return result;
}

string removeDuplicates2(string s) {
   int i=0; //Its tracks the size of resulting string
   for(int j=0;j<s.length();j++){
    s[i++]=s[j];
    // If last two elements are equal
    if(i>1 && s[i-1]==s[i-2]){
        i=i-2;
    }
   }
   s.resize(i);
   return s;
}

int main(){
    string a = "aaaaaaaa";
    string b = "aabcabcadd";
    string ans = removeDuplicates(a);
    // string ans = removeDuplicates2(a);
    cout<<ans<<endl;
}