#include <iostream>
#include <stack>
using namespace std;

string reverseString( string str){
    stack<char> s;
    for(size_t i=0; i<str.length(); i++){
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";
    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }
    return ans;
}

int main(){
    string str = "Akshat";
    cout<<"Reverse of string : "<<reverseString(str)<<endl;
}